#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
const int N=509;
int n,a[N],k,sum=0;
int f(int x){
	int b[n],sum=0;
	for(int i=0;i<n;i++){
		b[i]=a[i]%x;
		sum+=b[i];
	}
	int r=n-sum/x,res=0;
	sort(b,b+n);
	for(int i=0;i<r;i++)
		res+=b[i];
	return res;
}
int32_t main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> n >> k;
    for(int i=0;i<n;i++){
    	cin >> a[i];
    	sum+=a[i];
    }
    vector <int> d;
    d.push_back(sum);
    for(int i=1;i*i<=sum;i++){
    	if(sum%i)continue;
    	d.push_back(i),d.push_back(sum/i);
    }
    sort(d.rbegin(),d.rend());
    for(auto i:d){
    	if(f(i)<=k){
    		cout << i << " ";
    		break;
    	}
    }
}