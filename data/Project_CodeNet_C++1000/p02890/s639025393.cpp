#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000


int main(){
	
	int N;
	cin>>N;
	
	vector<int> C(N+1,0);
	for(int i=0;i<N;i++){
		int a;
		cin>>a;
		C[a]++;
	}
	sort(C.begin(),C.end());
	C.insert(C.begin(),0);
	auto S = C;
	for(int i=1;i<C.size();i++)S[i]+=S[i-1];
	
	vector<int> ans(N+1,0);
	
	for(int i=1;i<=N;i++){
		int ind = distance(C.begin(),lower_bound(C.begin(),C.end(),i));
		int cnt = 0;
		if(ind!=0)cnt += S[ind-1];
		cnt += i*(C.size()-ind);
		cnt/=i;
		cnt = min(cnt,N);
		if(cnt>=0)ans[cnt] = i;
	}
	
	for(int i=N-1;i>=0;i--)ans[i] = max(ans[i],ans[i+1]);
	for(int i=1;i<=N;i++)cout<<ans[i]<<endl;

	
	return 0;
}