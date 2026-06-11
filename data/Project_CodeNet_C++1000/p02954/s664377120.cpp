#include <bits/stdc++.h>
using namespace std;
//解き方を忘れたので解説AC
int main() {
  string s;
  cin>>s;
  int n=s.size();
  vector<int>a(n);
  for(int i=0;i<2;i++){
    int cnt=0;
    for(int j=0;j<n;j++){
      if(s[j]=='R')cnt++;
      else {
        a[j]+=cnt/2;
        a[j-1]+=(cnt+1)/2;
        cnt=0;
      }
    }
    reverse(a.begin(),a.end());
    reverse(s.begin(),s.end());
    for(int i=0;i<n;i++){
      if(s[i]=='L')s[i]='R';
      else s[i]='L';
    }
  }
  for(int i=0;i<n;i++){
    if(i!=n-1)cout<<a[i]<<" ";
    else cout<<a[i]<<endl;
  }
  return 0;
}

    