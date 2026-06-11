
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;


int main(){
    //整数の2乗の数のリストを作る(100は適当)
    vector<int> pow(200);
    for(int i=1; i<=200; i++){
            pow[i] = i*i;
    }

    int n, d;
    cin >> n >> d;
    //vector<vector<要素の型>> 変数名(要素数1, vector<要素の型>(要素数2, 初期値))
    vector<vector<int>> x(n,vector<int>(d,0));

    //入力
    for(int i=0; i<n; i++){
        for(int j=0; j<d; j++){
            cin >> x[i][j];
        }
    }
    int ans=0;
    //距離を計算 iが比べる点、jが比べられる点
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            int dif=0;
            for(int k=0; k<d; k++){
                dif += (x[i][k]-x[j][k])*(x[i][k]-x[j][k]);
            }
            //difがpowに含まれる(=平方数)ならans++
            for(int l=1; l<200; l++){
                if(pow[l]==dif) ans ++;
            }
        }
    }
    cout << ans << endl;


}