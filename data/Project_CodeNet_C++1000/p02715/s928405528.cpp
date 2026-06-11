#include <iostream>

using namespace std;

const int MOD = 1000000007;
long long fp(long long a, long long b){
	if(b==0)return 1;
	long long res = fp(a,b/2);
	res = (res*res)%MOD;
	if(b%2)res = (res*a)%MOD;
	return res;
}

long long re[100001];

int main(){
	
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n,k;
	long long res = 0;
	cin>>n>>k;
	for(long long i = k;i>=1;i--){
		long long f = k/i;
		long long can = fp(f,n);
		can -=re[i];
		if(can<0)can+=MOD;
		res = (res+i*can)%MOD;
		for(long long j = 1;j*j<=i;j++)if(i%j==0){
			re[j] = (re[j] + can)%MOD;
			if(j!=i/j){
				re[i/j] = (re[i/j] + can)%MOD;
			}
		}
	}
	cout<<res<<endl;
	
	return 0;
}