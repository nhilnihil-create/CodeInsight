#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n,m;
  string s;
  cin>>n>>m>>s;
  vector<int> vec;
  reverse(s.begin(),s.end());
  int now=0;
  while(now<n){
    for(int i=min(m,n-now);i>0;i--){
      if(s[now+i]=='0'){
        vec.push_back(i);
        now+=i;
        break;
      }
      if(i==1){
        cout<<-1<<endl;
        return 0;
      }
    }
  }
  reverse(vec.begin(),vec.end());
  for(int i=0;i<vec.size();i++){
    cout<<vec.at(i)<<" ";
  }
  cout<<endl;
  return 0;
}