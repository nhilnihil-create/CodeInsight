#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
typedef pair<ll,ll> P;

int main(){
   int n,d; cin >> n>>d;
   int cnt=0;
   for(int i=2*d+1;;i+=2*d+1){
       cnt++;
       if(i>=n)break;
   }
   cout << cnt<<endl;
        
    return 0;
}
