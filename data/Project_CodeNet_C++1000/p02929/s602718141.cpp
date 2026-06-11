#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)

#define L 0
#define R 1

int main(){

	lli n;
	cin>>n;
	n*=2;
	string s;
	cin>>s;

	lli data[200010];
	data[0] = L;

	lli cnt[2]={0};
	cnt[L]=1;

	for(lli i=1;i<n;i++){
		if(s.at(i-1)!=s.at(i))data[i] = data[i-1];
		else data[i] = (data[i-1]+1)%2;
		cnt[data[i]]++;
	}

	if(cnt[L]!=cnt[R] || data[n-1] == L || s.at(0)=='W' || s.at(n-1) == 'W'){
		cout<<0<<endl;
		return 0;
	}

	lli lCnt=0;
	lli pattern=1;

	for(lli i=0;i<n;i++){
		if(data[i]==L)lCnt++;
		else{
			pattern *= lCnt;
			pattern %= MOD;
			lCnt--;
		}
	}

	lli ans = pattern;
	for(lli i=1;i<=n/2;i++){
		ans *= i;
		ans %= MOD;
	}

	cout<<ans<<endl;
	return 0;
}