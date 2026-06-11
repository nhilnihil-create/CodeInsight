#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int K,tmp;
  long long Ans=0;
  cin>>K;
  for(int i=1;i<K+1;i++){
  for(int j=1;j<K+1;j++){tmp=__gcd(i, j);
  for(int l=1;l<K+1;l++){Ans+=__gcd(l, tmp);}
            }
  }
  cout<<Ans<<endl;
}