#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int inf = 1001001001;

int main() {
    ll n,x,count=0;
    cin >> n >> x;
    vector<ll> L(n+2,0);
    vector<ll> D(n+2,0);
    for(ll i=1; i<=n+1; i++){
        
        if(i==n+1){
            D.at(i)=D.at(i-1)+L.at(i-1);
            break;
        }
        
        cin >> L.at(i);
        D.at(i)=D.at(i-1)+L.at(i-1);
    }
    for(ll i=1; i<=n+1; i++){
        if(D.at(i)<=x){
            count++;
        }
        if(D.at(i)>x){
            break;
        }
    }

    cout << count << endl;
}



    