#include <bits/stdc++.h>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const long long INF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    ll n;
    cin >> n;
    ll sum=0;
    for(ll i = 0;i<=n;i++){
        if(i%3!=0&&i%5!=0){
            sum+=i;
        }
    }
    cout << sum << endl;

}