#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<map>
#include<iomanip>
#include<set>
#define rep(index,num) for(int index=0;index<num;index++)
#define rep1(index,num) for(int index=1;index<=num;index++)
#define brep(index,num) for(int index=num-1;index>=0;index--)
#define brep1(index,num) for(int index=num;index>0;index--)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-7
#define mp(a1,a2) make_pair(a1,a2)
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef long double ld;
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pint> vpint;
typedef vector<pll> vpll;
ll INFl=1e+18+1;
int INF=1e+9+1;
int N,A[300001],num[300001]={};
ll maxlen[300001];//maxlen[X]:X個の列を取り出すときの最大の長さ
ll kDksum[300001]={};
ll Dkbacksum[300001]={};
int main(){

	scan(N);
	rep(i,N){
		scan(A[i]);
		num[A[i]]++;
	}
	vint kazu;
	rep1(i,N) if(num[i]>0) kazu.push_back(num[i]);
	sort(ALL(kazu));
	map<ll,ll> kazukazu;
	ll kazusum=0;
	rep(j,kazu.size()){
		kazusum+=kazu[j];
		kazukazu[kazu[j]]++;
	}

	rep(j,N+1){
		kDksum[j+1]=kDksum[j]+j*kazukazu[j];
	}

	brep(j,N){
		Dkbacksum[j]=Dkbacksum[j+1]+kazukazu[j+1];
	}
	rep1(i,N){
		maxlen[i]=-((kDksum[i+1]+i*Dkbacksum[i])/i);//後でupperboundするので負にしてる
	}
	rep1(K,N){
		int ans=upper_bound(maxlen+1,maxlen+N+1,-K)-maxlen-1;
		prin(ans);
	}
	return 0;
}
