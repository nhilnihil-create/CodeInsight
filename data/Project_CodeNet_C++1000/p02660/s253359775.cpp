#include<bits/stdc++.h>
using namespace std;

int main(void){
  long long n; cin>>n;
  int rn=(int)sqrt(n),cnt,cnt2=0;
  for(int i=2; (i<rn)&&(n>1); ++i){
    cnt=0;
    while(n%i==0) n/=i, ++cnt;
    for(int j=1; (cnt-j)>=0; ++j) cnt-=j, ++cnt2;
  }if(n>1) ++cnt2;
  cout << cnt2 << endl;
  return 0;
}
