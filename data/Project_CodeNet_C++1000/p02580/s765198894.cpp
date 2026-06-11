#include"bits/stdc++.h"
#define ll long long
#define inf 100005
#define mod 1000000007
#define pb push_back
using namespace  std;

vector<vector<ll>>g(inf);
vector<ll>indgree(inf);
vector<ll>dist(inf);
bool visted[inf];



int main(){
	ll h,w,m,a,b,temp1,temp2;
	cin>>h>>w>>m;
	
	vector<ll>rw(h+1);
	vector<ll>cols(w+1);
	map<pair<ll,ll>,ll>mymap;
	for(ll i=0;i<m;i++){
		cin>>a>>b;
		mymap[make_pair(a,b)]=1;

		rw[a]++;
		cols[b]++;
	}

	a=-1;
	b=-1;

	for(ll i=1;i<=h;i++){
		if(a<rw[i]){
			a=rw[i];
		}
	}

	vector<ll>c,d;
	for(ll i=1;i<=w;i++){
		if(b<cols[i]){
			b=cols[i];
		}
	}

	for(ll i=1;i<=h;i++){
		if(rw[i]==a){
			d.pb(i);
		}
	}

	for(ll i=1;i<=w;i++){
		if(cols[i]==b){
			c.pb(i);
		}
	}
	
	ll flag=0;

	for(ll i=0;i<d.size();i++){
		for(ll j=0;j<c.size();j++){
			if(mymap[make_pair(d[i],c[j])]==0){
				flag=1;
				break;
			}
		}

		if(flag==1){
			break;
		}
	}

	if(flag==1){
		cout<<a+b<<endl;
	}else{
		cout<<(a+b-1)<<endl;
	}

	return 0;
}