#include<bits/stdc++.h>
using namespace std;
int main(void){
  signed long long a,b,c,k;cin>>a>>b>>c>>k;
  signed long long cnt=a;
  if(k<a) cnt-=(a-k);
  if((a+b)<k) cnt-=k-(a+b);
  cout<<cnt<<endl;
  return 0;
}
