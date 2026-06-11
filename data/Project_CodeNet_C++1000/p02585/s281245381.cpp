#include<bits/stdc++.h>
#define MOD (long long)(1e9+7)
using namespace std;
long long n,k,vis[5005];
long long p[5005],c[5005],sum[5005],ans=-1e18;
int main(){
	cin >> n >> k;
	for(int i=1; i<=n; i++) cin >> p[i];
	for(int i=1; i<=n; i++) cin >> c[i];
	for(int i=1; i<=n; i++){

	long long s=c[i];

	vector<long long>ti;
	ti.push_back(s);

	for(int j=p[i];j!=i;j=p[j])
    {
    s+=c[j];
    ti.push_back(s);
    }
	int len=ti.size();
	for(int j=0;j<len;j++){

        long long rest=k-j-1;
        if(rest<0)
            break;
        ans=max(ans,rest/len*max(0LL,s)+ti[j]);

	}


	}


	cout << ans;
}
