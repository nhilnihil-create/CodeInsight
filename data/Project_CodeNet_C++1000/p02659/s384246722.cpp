#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
int main(){
  long long a;
  double b;
  cin >> a >> b;
  if(a==0 || b==0){
    cout << 0 << endl;
    return 0;
  }
  long long num=b*100+0.000001;
  long long ans=num*a;
  ans/=100;
  cout << ans << endl;
}
