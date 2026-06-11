#include <bits/stdc++.h>
using namespace std;
//解答例写し
int main(){
  long long n;
  cin>>n;
  long long V=0;
  long long E=0;
  for(long long i=1;i<=n;i++){
    V+=i*(n-i+1);
  }
  for(long long i=0;i<n-1;i++){
    long long a,b;
    cin>>a>>b;
    if(a>b)swap(a,b);
    E+=a*(n-b+1);
  }
  long long ans=V-E;
  cout<<ans<<endl;
  return 0;
}
