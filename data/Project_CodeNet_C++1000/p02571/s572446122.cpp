#include <bits/stdc++.h>
using namespace std;
//#define ll long long 
#define all(v) v.begin(),v.end()
#define boost ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
/*
#define bigint __int128
__int128 abss(__int128 x){if(x>0)return x;
    return -x;
    }
*/
void solve() {
  string s,t,S;cin>>s>>t;bool ok =1;
  int l = s.length(),ll = t.length();
  int mx =  0;
  if(s==t){cout<<"0\n";}
  else{
    for(int i =0;i<=l-ll;i++){
    string tmp = s.substr(i,ll);
      int cnt = 0;
      
      for(int j = 0;j<ll;j++){
      if(tmp[j]==t[j]){++cnt;}
      }
      if(cnt>mx){
        mx = cnt;
        S = tmp;
      }
      
      cnt = 0;
    }
  if(ok)
  cout<<(ll-mx)<<"\n";
  else{cout<<"0\n";}
  }
}
int main()
{boost;
int t;t = 1;//cin>>t;
while(t--){solve();}
}
