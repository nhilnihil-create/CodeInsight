#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int n,a,b;
  while(1){
    cin >> n;
    if(n==0) break;
    int ans1=0,ans2=0;
    for(int i=0;i<n;i++){
      cin >> a >> b;
      if(a>b) ans1+=(a+b);
      else if(b>a)ans2+=(a+b);
      else{
	ans1+=a;
	ans2+=b;
      }
    }
    cout << ans1 << ' ' << ans2 << endl;
  }
  return 0;
}