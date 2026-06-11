#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  long long N,tmp;
  cin>>N;
  
  tmp=sqrt(N);
  while(tmp>0){
    if(N/tmp*tmp==N){break;}
    tmp--;
  }
  cout<<tmp+N/tmp-2<<endl;
}