#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
 
int main() {
  long long H1,M1,H2,M2,K,ans;
	cin>>H1>>M1>>H2>>M2>>K;
	ans=60*H2+M2-K-60*H1-M1;
	cout<<ans<<endl;
}