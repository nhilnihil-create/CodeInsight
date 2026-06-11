#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) begin(x), end(x)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

int is_prime[1000005];

int main(){
  int n;  
  cin>>n;
  int a[200005];
  rep(i,n){
    cin>>a[i];
    is_prime[a[i]]++;
  }
  sort(a,a+n);

  int ans=0;
  for(int i=1;i<=1000000;i++){
    if(is_prime[i]==0)continue;
    if(is_prime[i]==1) ans++;
    for(int j=2*i;j<=1000000;j+=i){
      is_prime[j]=0;
    }
  }

  cout<<ans<<endl;
  return 0;
}
