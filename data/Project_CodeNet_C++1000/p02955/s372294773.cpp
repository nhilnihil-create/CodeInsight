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

int N,K;
int A[555];

bool check(int g){
	vint lis;
	rep(i,N){
		if(A[i]%g==0)continue;
		lis.pb(A[i]%g);
	}

	sort(all(lis));
	for(int i=0;i<=lis.size();i++){
		int p=0,s=0;
		rep(j,i)p+=lis[j];
		for(int j=i;j<lis.size();j++)s+=g-lis[j];
		if(p!=s)continue;
		if(p<=K)return true;
	}
	return false;
}

signed main(){
	cin>>N>>K;
	rep(i,N)cin>>A[i];

	int sum=accumulate(A,A+N,0ll);
	int ans=0;
	for(int g=1;g*g<=sum;g++){
		if(sum%g)continue;
		if(check(g))chmax(ans,g);
		if(check(sum/g))chmax(ans,sum/g);
	}
	cout<<ans<<endl;
	return 0;
}