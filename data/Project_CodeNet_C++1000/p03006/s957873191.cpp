#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    ll N;
    cin >> N;
    vector<ll> x(N),y(N);
    rep(i,N){
        cin >> x[i] >> y[i];
    }
    ll M = 0;
    rep(i,N){
        rep(j,N){
            if(i == j)continue;
            ll vecx = x[j] - x[i];
            ll vecy = y[j] - y[i];
            ll cnt = 0;
            rep(k,N){
                rep(m,N){
                    if(k==m)continue;
                    if(vecx == x[m]-x[k] && vecy == y[m] - y[k]){
                        cnt++;
                    }
                }
            }
            M = max(M,cnt);
        }
    }
    cout << N - M << endl;
    /*vector<pair<ll,ll>> p(N);
    rep(i,N){
        cin >> p[i].first >> p[i].second;
    }
    
    sort(p.begin())
    ll ans = 50;
    rep(i,N){
        rep(j,N){
            ll dx = p[i].first - p[j].first;
            ll dy = p[i].second - p[j].second;
            vector<bool> used(N,false);
            used[i] = true;
            used[j] = true;
            ll curx = p[j].first;
            ll cury = p[j].second;
            ll cnt = 0;
            rep(k,N-2){
                rep(m,N-2){
                    if(used[m])continue;
                    if(curx+dx == p[m].first && cury+dy == p[m].second){
                        used[m] = true;
                        cnt++;
                        break;
                    }
                }
            }
        }
    }*/

}
