#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P pair<ll,ll>
#define FOR(I,A,B) for(ll I = ll(A); I < ll(B); ++I)
#define FORR(I,A,B) for(ll I = ll((B)-1); I >= ll(A); --I)
#define TO(x,t,f) ((x)?(t):(f))
#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin()) //xi>=v  x is sorted
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin()) //xi>v  x is sorted
#define NUM(x,v) (POSU(x,v)-POSL(x,v))  //x is sorted
#define REV(x) (reverse(x.begin(),x.end())) //reverse
ll gcd_(ll a,ll b){if(a%b==0)return b;return gcd_(b,a%b);}
ll lcm_(ll a,ll b){ll c=gcd_(a,b);return ((a/c)*(b/c)*c);}
#define NEXTP(x) next_permutation(x.begin(),x.end())
const ll INF=ll(1e16)+ll(7);
const ll MOD=1000000007LL;
#define out(a) cout<<fixed<<setprecision((a))
//tie(a,b,c) = make_tuple(10,9,87);
#define pop_(a) __builtin_popcount((a))
ll keta(ll a){ll r=0;while(a){a/=10;r++;}return r;}



int main(){

  string S;
  cin >> S;
  vector<ll> x(S.size()+3,INF),ans(S.size()+100,0);
  x[0] = 0;
  FOR(i,1,S.size()){
    x[i] = x[i-1] + (S[i]!=S[i-1]);
  }


  FOR(i,0,S.size()){    
    if(S[i]=='L'){//左に行く
      ll ind = POSU(x,(x[i]-1));
      ll sa = (i-ind)%2;
      if(i<ind)cout << "EEEE" << i << " " << ind << endl;
      if(sa==0){
        ans[ind]++;
      }else{
        ans[ind-1]++;
      }
    }else{
      ll ind = POSU(x,x[i]);
      ll sa = (ind-i)%2;
      if(i>ind)cout << "EEEEA" << endl;
      if(sa==0){
        ans[ind]++;
      }else{
        ans[ind-1]++;
      }
    }
  }

  FOR(i,0,S.size()){
    if(i!=0)cout<<" ";
    cout << ans[i];
  }
  cout << endl;


}


