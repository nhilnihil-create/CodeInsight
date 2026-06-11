#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int inf = 1001001001;
 
int main(){

    ll N,sum=0;
    cin >> N;
    vector<ll> data(N+1);
    rep(i,N+1){
        cin >> data.at(i);
    }
    vector<ll> ushiro(N+1);
    vector<ll> mae(N+1);
    if(N==0 && data.at(0)!=1){
        cout << -1 << endl;
        return 0;
    }
    if(N==0 && data.at(0)==1){
        cout << 1 << endl;
        return 0;
    }
    if(N!=0 && data.at(0)==1){
        cout << -1 << endl;
        return 0;
    }
    for(ll i=N; i>=0; i--){
        if(i==N){
            ushiro.at(i)=data.at(N);
            continue;
        }
        ushiro.at(i)=ushiro.at(i+1)+data.at(i);
    }
    for(ll i=0; i<=N; i++){
        if(i==0){
            mae.at(i)=1;
            sum++;
            continue;
        }
        mae.at(i)=min((mae.at(i-1))*2,ushiro.at(i));
        sum+=mae.at(i);
        mae.at(i)-=data.at(i);
        if(mae.at(i)<0){
            cout << -1 << endl;
            return 0;
        }
    }

    
    cout << sum << endl;
}