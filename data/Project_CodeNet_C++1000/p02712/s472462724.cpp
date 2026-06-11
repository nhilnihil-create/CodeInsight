#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  long long Ans=0;
  cin>>N;
  rep(i,N+1){if(i%3!=0 && i%5!=0){Ans+=i;}}
  cout<<Ans<<endl;
}