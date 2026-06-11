#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  
  cout<<n<<":";
  
  int a=n;
  for(int i=2;i*i<=a;i++){
    while(n%i==0){
      cout<<" "<<i;
      n/=i;
    }
  }
  if(n>1) cout<<" "<<n;
  cout<<endl;

  return 0;
}
