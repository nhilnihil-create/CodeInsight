#include <bits/stdc++.h>

using namespace std;

long long int gcd(long long int p,long long int q){
if(p % q == 0)return q;
 return gcd(q, p % q);
  }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int k;
	cin>>k;
	long long int ans=0;
	long long int m;
	for(long long int i=1;i<=k;i++){
		for(long long int j=1;j<=k;j++){
			for(long long int l=1;l<=k;l++){
				m=gcd(gcd(i,j),l);
				ans+=m;
			}
		}
	}
	cout<<ans;
	return 0;
}