#include <bits/stdc++.h>
#define rep(i,s,n) for(int i=s;i<n;i++)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
using P=pair<int,int>;
using G=vector<vector<int>>;
using ll=long long;




int main(int argc, char **argv){
	ll n; cin>>n;
	pair<ll,ll> robot[n];

	rep(i,0,n){
		ll xi,li; cin>>xi>>li;
		robot[i]=make_pair(xi+li,xi-li);
	}

	sort(robot,robot+n);

	ll ans=1;
	ll bord=robot[0].first;

	rep(i,1,n){
		if(bord<=robot[i].second){
			ans++;
			bord=robot[i].first;
		}
	}

	cout<<ans<<endl;
}
