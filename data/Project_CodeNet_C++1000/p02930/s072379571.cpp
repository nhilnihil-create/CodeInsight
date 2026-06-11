#include<bits/stdc++.h>
#define LL long long
#define REP(i,n) for(int i=0;i<(n);++i)
#define PER(i,n) for(int i=n-1;i>=0;--i)
#define REPA(i,n) for(int i=1;i<(n);++i)
#define foreach(i, n) for(auto &i:(n))
#define PII pair<int,int>
#define PLI pair<long long, int>
#define PLL pair<long long, long long>
#define MOD ((LL)1e9+7) 
#define INF ((int)1e9+7)
#define INFLL ((LL)1e18)
#define ALL(x) (x).begin(),(x).end()
#define BIT(x) (1LL << (x))
using namespace std;

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

LL factorial(int x){
	if(x<=1)return 1;
	return x * factorial(x-1) % MOD;
}

bool flag = false;

void output(LL x){
	if(flag)cout << " ";
	cout << x;
	flag=true;
}

void outendl(){
	flag=false;
	cout << endl;
}

int countbit(int x){
	for(int i=10;;--i){
		if(BIT(i)&x)return i + 1;
	}
}

int main(){
	int N;
	cin >> N;
	vector<vector<int>> line(N);
	vector<vector<int>> ans(N, vector<int>(N, 0));
	REP(i, N){
		line[i].push_back(i);
	}
	int count = 1;
	while(line.size()>1){
		vector<vector<int>> ne;
		for(int i=0;i<line.size();i+=2){
			if(i+1==line.size()){
				ne.push_back(line[i]);
				continue;
			}
			foreach(j, line[i]){
				foreach(k, line[i+1]){
					ans[j][k]=count;
					ans[k][j]=count;
				}
			}
			line[i].insert(line[i].end(), ALL(line[i+1]));
			ne.push_back(line[i]);
		}
		++count;
		line = ne;
	}
	REP(i, N){
		for(int j=i+1;j<N;++j){
			output(ans[i][j]);
		}
		outendl();
	}
	return 0;
}
