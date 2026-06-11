#include <bits/stdc++.h>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const long long INF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int gcd(ll a, ll b){
    if (a%b == 0)return(b);
    else return(gcd(b,a%b));
}

int main(){
    int k;cin>>k;
    ll sum=0;
    for(int i =1;i<=k;i++){
        for(int j =1;j<=k;j++){
            for(int l =1;l<=k;l++){
                int x=gcd(i,j);
                int y=gcd(x,l);
                sum+=y;
            }
        }
    }
    cout << sum << endl;

}