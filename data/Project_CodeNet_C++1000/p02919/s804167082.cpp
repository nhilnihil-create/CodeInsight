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
#define eps 1e-9
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
	int N,P[100005];
	int pos[100005];
	scan(N);
	set<int> st;
	st.insert(-2);
	st.insert(-1);
	st.insert(N);
	st.insert(N+1);
	rep(i,N){
		scan(P[i]);
		pos[P[i]]=i;
	}
	ll ans=0;
	brep1(i,N){
		int le2,le1,ri1,ri2;
		st.insert(pos[i]);
		auto itr=st.find(pos[i]);
		itr--;
		le1=*itr;
		itr--;
		le2=*itr;
		itr++; itr++; itr++;
		ri1=*itr;
		itr++;
		ri2=*itr;
		ll sum=0;
		if(ri1<N) sum+=(ll)(ri2-ri1)*(pos[i]-le1);
		if(le1>-1) sum+=(ll)(le1-le2)*(ri1-pos[i]);
		sum*=i;
		ans+=sum;
	}
	prin(ans);
	return 0;
}
