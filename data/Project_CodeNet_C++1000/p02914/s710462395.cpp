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
#include<assert.h>
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
int main(){
	int N;
	ll A[100001];
	ll Axor=0;
	scan(N);
	rep(i,N){
		scan(A[i]);
		Axor^=A[i];
	}
	rep(i,N) A[i] &= ~Axor;
	ll rank=0;
	int top[100001]={};
	brep(j,61){
		int i=rank;
		int flag=0;
		for(;i<N;i++){
			if((A[i]>>j)&1){
				swap(A[i],A[rank]);
				flag=1;
				break;
			}
		}
		if(flag==0) continue;
		top[rank]=j;
		rep(k,N){
			if(rank==k) continue;
			if((A[k]>>j)&1){
				A[k]^=A[rank];
			}
		}
		rank++;
	}
	ll x=0;
	brep(j,61){
		ll nx=x|(1LL<<j);
		ll b=nx;
		rep(i,rank){
			if(b>>top[i]&1) b^=A[i];
		}
		if((b&nx)==0){
			x=nx;
		}
	}
	ll ans=Axor+x*2;
	prin(ans);
	return 0;
}
