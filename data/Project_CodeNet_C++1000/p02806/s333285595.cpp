#include<bits/stdc++.h>
using  namespace std;
int main(){
  int n,sum=0;
  cin >> n;
  string s[n];
  int a[n];
  for(int i=0;i<n;i++)cin >> s[i] >> a[i];
  string x;
  cin >> x;
  for(int i=0;i<n;i++){
    if(x==s[i]){
      for(int k=i+1;k<n;k++)sum+=a[k];
      break;
    }
  }
  cout << sum << endl;
}