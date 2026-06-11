#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,LL> PL;

PL po(LL x){
  LL y=sqrt(x-1)+1;
  while((y-1)*(y-1)>=x)y--;
  if(x>y*(y-1))return PL(y,y);
  else return PL(y-1,y);
}
int main(){
  LL n;cin>>n;
  LL a=po(n).first,b=po(n).second;
  LL sa=a*b-n;
  cout<<0<<" "<<1<<" "<<a<<" "<<0<<" "<<a-sa<<" "<<b<<endl;
  return 0;
}
