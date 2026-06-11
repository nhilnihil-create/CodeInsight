#include<bits/stdc++.h>
using namespace std;
int main(void){
long long a,b;
  cin>>a>>b;
  long long ans=0;

for(long long i=22;i<=b;i++){
  long long l=i/10;
  long long r=i%10;
  if(l*r<=a && r>1) ans++;
  }
  
  cout<<ans<<endl;
}
