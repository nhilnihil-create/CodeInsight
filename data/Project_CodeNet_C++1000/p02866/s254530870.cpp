#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  long long n;
  cin >> n;
  long long a[n-1];
  rep(i,n-1)a[i]=0;
  long long u;
  long long p=998244353,ans=1;
  cin >> u;
  if(u!=0){
    cout << 0 << endl;
    return 0;
  }
  rep(i,n-1){
    long long j;
    cin >> j;
    if(j==0){
      cout << 0 << endl;
      return 0;
    }
    j--;
    a[j]++;
  }
  rep(i,n-2){
    long long b=a[i],c=a[i+1];
    if(c==0)continue;
    else{
      rep(o,c)ans=ans*b%p;
    }
  }
  cout << ans << endl;
}
