#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
#define REP(i,n) for(ll i = 0;i < (ll)n;i++)
#define REPD(i,n) for(ll i = (ll)n - 1;i >= 0;i--)
#define ALL(x) (x).begin(),(x).end()
#define FILLl(n,first_dimension_size,value) fill((ll*)n,(ll*)(n+first_dimension_size),value)
#define FILL(n,first_dimension_size,value) fill((int*)n,(int*)(n+first_dimension_size),value)
#define INF (1 << 30)
#define MOD 1000000007
//int dy[4] = {-1,0,0,1};
//int dx[4] = {0,1,-1,0};



int main(){
  
  string s;
  cin >> s;
  ll res = 1;
  string os = "";
  os += s[0];
  for(int i = 1;i < s.size();i++){
    if(os.size() != 1){
      res++;
      os = s[i];
    }else{
      if(s[i] != os[0]){
        res++;
        os = s[i];
      }else{
        res++;
        if(i+1 < s.size()){
          os = s[i]+s[i+1];
          i++;
        }else{
          res--;
        }
      }
    }
  }
  cout << res << endl;

  
  


  

  return 0;
}