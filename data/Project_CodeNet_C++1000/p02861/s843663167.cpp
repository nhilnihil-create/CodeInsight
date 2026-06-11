#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long LL;

LL factorialNumber(int N){
  LL ans=N;
  while(--N) ans*=N;
  return ans;
}

int main() {
  int n; cin>>n;
  int x[n],y[n]; for(int i=0;i<n;i++) cin>>x[i]>>y[i];
  double routeSum=0;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      routeSum+=sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
    }
  }
  double ans=factorialNumber(n-1)*2*routeSum/factorialNumber(n);
  printf("%.7lf",ans);
}

