#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
using pii = pair<int, int>;

int main() {
  string s; cin>>s;
  int n,q,f; cin>>n;
  string t;
  int count1=0;
  rep(i,n){
    cin>>q;
    if(q==1){count1++;}
    if(q==2){
      cin>>f>>t;
      if((count1+f)%2==0){s.append(t);}
      if((count1+f)%2==1){s.insert(0,t);}
    }
  }
  if(count1%2==1){reverse(s.begin(), s.end());}
  cout<<s<<endl;
}

