#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
string a;
vector<int> v;
lld dp[1000001];
int main(void){
	int n;
	cin >> n >> a;
	dp[0] = 0;
	for(int e=1;e<1000001;e++) {
		int num = 0,now = e;
		while(now%2==0){
			now/=2;
			num++;
		}
		dp[e] = dp[e-1] + num;
	}
	for(int e=0;e<n-1;e++) v.push_back(abs(a[e]-a[e+1]));
	int tot = 0,nt = 0;
	for(int e=0;e<n-1;e++){
		if(v[e]==1){
			nt++;
			int nn = n-2, rr = e;
			int diff = dp[nn] - dp[rr] - dp[nn-rr];
			if(diff==0) tot ^= 1;
		}
	}
	if(tot) printf("1");
	else{
		if(nt) printf("0");
		else{
			for(int e=0;e<n-1;e++) v[e]/=2;
			int tot = 0;
			for(int e=0;e<n-1;e++){
				if(v[e]==1){
					int nn = n-2,rr = e;
					int diff = dp[nn] - dp[rr] - dp[nn-rr];
					if(diff==0) tot ^= 1;	
				}
			}
			if(tot) printf("2");
			else printf("0");
		}
	}
}