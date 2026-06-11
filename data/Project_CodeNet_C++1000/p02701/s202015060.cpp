#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,ans=0;
  cin>>n;
  map<string,int>p;
  for(int i=0;i<n;i++){
    string s;
    cin>>s;
    p[s]++;
    if(p[s]==1){
      ans++;
    }
  }
  cout<<ans<<endl;
}
