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
  
  int n,sa,sb,ga,gb;
  string s;
  cin >> n >> sa >> sb >> ga >> gb >> s;
  vector<bool> dpa(s.size(),0),dpb(s.size(),0);
  sa--,sb--,ga--,gb--;
  dpa[sa] = dpb[sb] = true;
  for(int i = sa;i < s.size();i++){
    if(dpa[i] == false)continue;
    if(i+1 < s.size() && s[i+1] == '.'){
      dpa[i+1] = true;
    }
    if(i+2 < s.size() && s[i+2] == '.'){
      dpa[i+2] = true;
    }
  }
  for(int i = sb;i < s.size();i++){
    if(dpb[i] == false)continue;
    if(i+1 < s.size() && s[i+1] == '.'){
      dpb[i+1] = true;
    }
    if(i+2 < s.size() && s[i+2] == '.'){
      dpb[i+2] = true;
    }
  }
  if(!dpa[ga] || !dpb[gb]){
    cout << "No" << endl;
  }else if(ga > gb){
    bool is = false;
    int cnt = 0;
    for(int i = sb-1;i <= gb+1;i++){
      if(s[i] == '.')cnt++;
      else cnt = 0;
      if(cnt >= 3){
        is = true;
        break;
      }
    }
    if(is)cout << "Yes" << endl;
    else cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
  }

  
  


  

  return 0;
}