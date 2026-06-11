#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B,C,L,R;
string S,T;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;


int main(){
  cin>>N;  
  multiset<ll> goal; 
  rep(j,(1LL<<N)){ 
    cin>>A; 
    goal.insert(A); 
  } 
  queue<ll> now;
  auto big = goal.end(); 
  --big;
  now.push(*big); 
  goal.erase(big);
  rep(i,N){ 
    rep(j,(1LL<<i)){ 
      ll sli = now.front(); 
      now.pop(); 
      now.push(sli); 
      auto son = goal.lower_bound(sli);
      /*cout<<i<<j<<endl;
      for(ll c : goal) cout<<c; 
      cout<<endl; */
      if(son == goal.begin()) {
        cout<<"No"<<endl; 
        return 0;
      } 
      --son; 
      now.push(*son);
      goal.erase(son); 
    } 
  } 
  cout<<"Yes"<<endl; 
}
