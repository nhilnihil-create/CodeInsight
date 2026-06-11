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


int quad(pint p){
	if(p.fi>0&&p.se>=0)return 0;
	if(p.se>0&&p.fi<=0)return 1;
	if(p.fi<0&&p.se<=0)return 2;
	return 3;
}
int dot(pint p,pint q){
	return p.fi*q.fi+p.se*q.se;
}
int cross(pint p,pint q){
	return p.fi*q.se-p.se*q.fi;
}
pint operator+(pint p,pint q){
	return pint(p.fi+q.fi,p.se+q.se);
}
pint operator-(pint p,pint q){
	return pint(p.fi-q.fi,p.se-q.se);
}

int norm(pint p){
	return dot(p,p);
}

signed main(){
	int N;
	cin>>N;

	vpint ps;
	rep(i,N){
		int x,y;
		cin>>x>>y;
		if(x||y)ps.eb(x,y);
	}
	N=ps.size();

	sort(all(ps),[&](pint p,pint q){
		if(quad(p)!=quad(q)){
			return quad(p)<quad(q);
		}
		return cross(p,q)>0;
	});

	vpint ps_=ps;
	ps.insert(ps.end(),all(ps_));

	int ans=0;
	rep(i,N){
		pint sum;
		rep(j,N){
			sum=sum+ps[i+j];
			chmax(ans,norm(sum));
		}
	}

	printf("%.20Lf\n",sqrtl(1.0L*ans));
	return 0;
}