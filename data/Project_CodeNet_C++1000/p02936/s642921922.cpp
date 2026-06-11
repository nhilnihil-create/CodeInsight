#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;
vector<long long> ki(200001,-1),button(200001,0);
vector<vector<long long>> kankei(200001);

void dfs(long long now,long long point){
	point+=button.at(now);
	ki.at(now)=point;

	for(auto a:kankei.at(now)){
		if(ki.at(a)==-1){
			dfs(a,point);
		}
	}
}

int main(){
	long long n,q;
	cin>>n>>q;
	for(long long i=0;i<n-1;i++){
		long long a,b;
		cin>>a>>b;
		kankei.at(a).push_back(b);
		kankei.at(b).push_back(a);
	}
	for(long long i=0;i<q;i++){
		long long p,x;
		cin>>p>>x;
		button.at(p)+=x;
	}

	dfs(1,0);

	for(long long i=1;i<=n;i++){
		cout<<ki.at(i)<<endl;
	}

	return 0;
}
