#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<n;i++)
int main() {
  int n;
  cin>>n;
  vector<int>l(n);
  for(int i=0;i<n;i++)
    cin>>l[i];
  int ans=0;
  sort(l.begin(),l.end());
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      for(int k=j+1;k<n;k++){
        if(l[i]+l[j]>l[k]){
          if(l[i]!=l[j] && (l[j]!=l[k] && l[k]!=l[i]))
            ans++;
        }
      }
    }
  }
  cout<<ans<<endl;
}
