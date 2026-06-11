#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
	int k,q;
	cin>>k>>q;
	vector<int> d(k);
	for (int i = 0; i < k; i++)cin>>d[i];
	for (int i = 0; i < q; i++){
		int n,x,m;
		cin>>n>>x>>m;
		vector<int> d_mod_m(k);
		int zero=0;
		ll sum=0;
		for (int j = 0; j < k; j++){
			d_mod_m[j]=d[j]%m;
			sum+=d_mod_m[j];
			if(d_mod_m[j]==0){
				zero+=(n-1)/k;
				if(j<(n-1)%k)zero++;
			}
		}
		sum*=(n-1)/k;
		for (int i = 0; i < (n-1)%k; i++){
			sum+=d_mod_m[i];
		}
		sum+=x;
		int large=sum/m-x/m;
		cout<<n-1-zero-large<<endl;
	}
}