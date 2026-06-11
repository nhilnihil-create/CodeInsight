#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second

using vint=vector<int>;
using pint=pair<int,int>;
using vpint=vector<pint>;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
	ost<<"{"<<p.first<<","<<p.second<<"}";
	return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&v){
	ost<<"{";
	for(int i=0;i<v.size();i++){
		if(i)ost<<",";
		ost<<v[i];
	}
	ost<<"}";
	return ost;
}

int msb(int x){
	return 63-__builtin_clzll(x);
}

int N;
int A[111111];

signed main(){
	cin>>N;
	rep(i,N)cin>>A[i];

	int base=0;
	rep(i,N)base^=A[i];

	rep(i,60){
		if(!(base>>i&1))continue;
		rep(j,N)if(A[j]>>i&1)A[j]^=1ll<<i;
	}

	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			if(A[i]<A[j])swap(A[i],A[j]);
		}
		if(A[i]==0)break;
		for(int j=0;j<N;j++){
			if(i==j)continue;
			if(A[j]>>msb(A[i])&1)A[j]^=A[i];
		}
	}


	int X=0;
	rep(i,N)X^=A[i];
	int Y=base^X;
	cout<<base+(X&Y)*2<<endl;
	return 0;
}