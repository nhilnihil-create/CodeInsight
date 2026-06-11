//解説の方針B:進む方向を絞る
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

//内積 及び 外積
ll dot(ll x1, ll y1, ll x2, ll y2) { return x1*x2 + y1*y2; }
ll cross(ll x1, ll y1, ll x2, ll y2) { return x1*y2 - x2*y1; }

int main()
{
    int N;
    cin >> N;
    ll X[N], Y[N];
    for(int i = 0; i < N; ++i) cin >> X[i] >> Y[i];

    ll ans = 0;
    for(int i = 0; i < N; ++i) {
        ll gx = X[i], gy = Y[i];
        for(int j = 0; j < 4; ++j) {
            {
                //90度回転
                ll nx = -gy, ny = gx;
                gx = nx, gy = ny;
            }

            ll  sx = 0, sy = 0, // 進む方向から-90<Θ<+90°の範囲のエンジンをすべて足したもの
                px = 0, py = 0, // 進む方向から丁度+90°の角度のエンジンをすべて足したもの
                qx = 0, qy = 0; // 進む方向から丁度-90°の角度のエンジンをすべて足したもの

            for(int k = 0; k < N; ++k){
                if(dot(gx, gy, X[k], Y[k]) < 0) continue;
                if(dot(gx, gy, X[k], Y[k]) > 0) {
                    sx += X[k]; sy += Y[k];
                    continue;
                }
                //dot() == 0,進む方向と直角のX, Yについて
                if(cross(gx, gy, X[k], Y[k]) > 0) {
                    px += X[k]; py += Y[k];
                    continue;
                }
                if(cross(gx, gy, X[k], Y[k]) < 0) {
                    qx += X[k]; qy += Y[k];
                    continue;
                }
            }
            
            // s, s + p, s + q, s + p + qの内もっとも絶対値が大きくなるものを調べる
            for(int s = 0; s < 4; ++s) {
                //ビットで場合分け
                ll bx = sx, by = sy;
                if(s&1) {bx += px; by += py;}
                if(s&2) {bx += qx; by += qy;}
                ans = max(ans, bx*bx + by*by);
            }

        }
    }

    cout << fixed <<setprecision(12) << sqrt(ans) << endl;
    return 0;
}