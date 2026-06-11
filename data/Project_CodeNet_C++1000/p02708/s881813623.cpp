#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<iostream>
#include<sstream>
#include<utility>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<stack>
#include<functional>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
const ll MOD=1e9+7;


ll sum(ll f,ll t)
{
	ll res=0;
	return ((f+t)*(t-f+1))/2;
	return res;
}

int main()
{
	ll N,K;
	cin>>N>>K;
	//K~N
	ll bscnt=0;
	for(ll i=K-1;i<=N;i++){
		ll mm=sum(1,i);
		ll mx=sum(N-(i),N);
		bscnt=(bscnt+(mx-mm+1))%MOD;
	}
	cout<<bscnt<<endl;
}