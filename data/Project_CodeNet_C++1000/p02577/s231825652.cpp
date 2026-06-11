#include<bits/stdc++.h>
using namespace std;
int main(){
  char a[200010];
  cin >> a;
  int n=strlen(a);
  int sum=0;
  for(int i=0;i<n;++i){
    sum+=a[i]-'0';
  }
  if(sum%9==0) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}

    
  
