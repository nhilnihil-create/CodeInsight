#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
typedef long long LL;
int N;

LL x[200001];
LL y[200001];
vector<LL>v,w;
int main(){
	cin>>N;
	REP(i,N){
		cin>>x[i]>>y[i];
		v.push_back(x[i]+y[i]);
		w.push_back(x[i]-y[i]);
	}
	sort(v.begin(),v.end());
	sort(w.begin(),w.end());
	cout<<max(v[N-1]-v[0],w[N-1]-w[0])<<endl;
	return 0;
}