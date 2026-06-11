#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}


int main() {
    ll x;
    cin >> x;
    for(ll i = -200;i<=200;i++) {
        for(ll j = -200;j<=200;j++) {
            if(pow(i,5) - pow(j,5) == x) {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }    
}
    


