#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  string s;
  cin >> n >> s;
  
  int ans=0;
  
  for(int i=0;i<1000;i++){
    int p=0;
    int k=0;
    while(k<n){
      if(p==0&&s[k]==i/100+'0') p++;
      else if(p==1&&s[k]==i/10%10+'0') p++;
      else if(p==2&&s[k]==i%10+'0') p++;
      k++;
    }
    if(p==3) ans++;
  }
  
  cout << ans << endl;
}