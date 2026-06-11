#include<bits/stdc++.h>
#define LL long long
#define REP(i,n) for(int i=0;i<(n);++i)
#define PER(i,n) for(int i=n-1;i>=0;--i)
#define REPA(i,n) for(int i=1;i<(n);++i)
#define foreach(i, n) for(auto &i:(n))
#define PII pair<int,int>
#define PLI pair<long long, int>
#define PLL pair<long long, long long>
#define PAIR pair<double, double>
#define ALL(x) (x).begin(),(x).end()
#define BIT(x) (1LL << (x))
#define PI acos(-1)
const LL MOD = (LL)1e9+7;
const LL INF = (LL)1e9+7;
const LL INFLL = (LL)1e18;
using namespace std;
template<class t, class u> bool chmax(t &a, u b){if(a<b){a=b;return true;}return false;}
template<class t, class u> bool chmin(t &a, u b){if(a>b){a=b;return true;}return false;}

LL modpow(LL x, LL b){
	LL res = 1;
	while(b){
		if(b&1)res = res * x % MOD;
		x = x * x % MOD;
		b>>=1;
	}
	return res;
}

LL modinv(LL x){
	return modpow(x, MOD-2);
}

int main(){
	int n;
	cin >> n;
	vector<LL> line(n);
	LL sum = 0;
	foreach(i, line){
		cin >> i;
		sum ^= i;
	}

	foreach(i, line){
		i &= ~sum;
	}
	int rank = 0;

	PER(i, 61){
		int j;
		for(j=rank;j<n;++j)if(line[j]&BIT(i))break;
		if(j==n)continue;
		swap(line[rank], line[j]);
		REP(k, n)if(k!=rank)chmin(line[k], line[k]^line[rank]);
		++rank;
	}

	LL asum = 0;
	foreach(i, line)asum ^= i;
	cout << sum + asum * 2 << endl;

	return 0;

}
