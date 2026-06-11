#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int num[100005];

int main() {
  int n,m,k,p;
  scanf("%d%d%d%d",&n,&m,&k,&p);
  for(int i=1;i<=n;i++) scanf("%d",&num[i]);
  sort(num+1,num+n+1);
  int ans=p;
  ll s=num[n-p+1];
  for(int i=n-p;i>0;i--) {
  	if (num[i]+m<num[n-p+1]) break;
  	s+=num[i];
  	int t=k-(p+i-2);
  	if (t<=0||(ll)(num[i]+m)*(n-p-i+2)-s>=(ll)m*t) ans++;
  	else break;
  }
  printf("%d\n",ans);
  return 0;
} 