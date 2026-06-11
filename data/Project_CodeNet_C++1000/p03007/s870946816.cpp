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

signed main(){
	int N;
	cin>>N;
	vint A(N);rep(i,N)cin>>A[i];

	int m=min_element(all(A))-A.begin();
	int M=max_element(all(A))-A.begin();

	vpint ans;
	if(A[M]<=0){
		rep(i,N){
			if(i==M)continue;
			ans.eb(A[M],A[i]);
			A[M]-=A[i];
		}
	}
	else if(A[m]>=0){
		int last=N-1;
		if(last==m)last--;
		rep(i,N){
			if(i==last){
				ans.eb(A[last],A[m]);
				A[last]-=A[m];
				continue;
			}
			if(i==m)continue;
			ans.eb(A[m],A[i]);
			A[m]-=A[i];
		}
	}
	else{
		rep(i,N){
			if(i==M||i==m)continue;
			if(A[i]>=0){
				ans.eb(A[m],A[i]);
				A[m]-=A[i];
			}
		}
		rep(i,N){
			if(i==M)continue;
			if(A[i]>=0)continue;
			ans.eb(A[M],A[i]);
			A[M]-=A[i];
		}
	}

	cout<<ans.back().fi-ans.back().se<<endl;
	rep(i,N-1)cout<<ans[i].fi<<" "<<ans[i].se<<endl;
	return 0;
}