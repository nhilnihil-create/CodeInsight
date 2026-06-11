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

int N;
int P[111111];

signed main(){
	cin>>N;
	rep(i,N)cin>>P[i];
	vint ord(N);iota(all(ord),0);
	sort(all(ord),[&](int i,int j){
		return P[i]>P[j];
	});

	set<int>idx;
	int ans=0;
	for(auto i:ord){
		vint v(4);
		auto it=idx.lower_bound(i);
		if(it==idx.end())v[2]=v[3]=N;
		else{
			v[2]=*it;
			it++;
			if(it==idx.end())v[3]=N;
			else v[3]=*it;
		}
		it=idx.lower_bound(i);
		if(it==idx.begin()){
			v[0]=v[1]=-1;
		}
		else{
			it--;
			v[1]=*it;
			if(it==idx.begin())v[0]=-1;
			else{
				it--;
				v[0]=*it;
			}
		}
		ans+=(v[3]-v[2])*(i-v[1])*P[i];
		ans+=(v[2]-i)*(v[1]-v[0])*P[i];
		idx.insert(i);
	}
	cout<<ans<<endl;
	return 0;
}