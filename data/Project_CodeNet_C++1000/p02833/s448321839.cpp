#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  long long S;
  cin>>S;
  long long Ans=0;
  if(S%2==1){cout<<0<<endl;}else
  {S=S/10;Ans+=S;while(S>0){Ans+=S/5;S=S/5;}cout<<Ans<<endl;}
}
