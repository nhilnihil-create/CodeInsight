#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define drep(i,a,b) for(ll i=(a);i>=(b);--i)
#define SIZE(a) int((a).size())
#define out(a) cout<<(a)<<endl;
const int INF=INT_MAX;
const int MAX = 510000;
const ll MOD = 1000000007;
ll fac[MAX], finv[MAX], inv[MAX];


int main(){
  string s;cin>>s;
  vll c(0),d(0),ans(s.size(),0);
  for(int i = 0 ; i < s.size() - 1; ++i) {
        if(s[i] == 'R' && s[i+1] == 'L') {
            int j = i ; 
            while(j>= 0 && s[j] == 'R') {
                if((i-j)%2 ==0)
                    ans[i]++;
                else {
                    ans[i+1]++ ; 
                }
                j--;
            }
 
            j = i + 1; 
            while(j < s.size() && s[j] =='L'){
                if((j-i)%2==0)
                    ans[i]++ ; 
                else 
                    ans[i+1]++;
                    j++;
            }
       }
  }
  rep(i,0,s.size()){
    cout<<ans[i]<<' ';
  }
  cout<<endl;
}






