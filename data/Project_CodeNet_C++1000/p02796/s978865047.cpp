#include <bits/stdc++.h>
#define rep(i,s,n) for(int i=s;i<n;i++)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
using P=pair<int,int>;
using G=vector<vector<int>>;
using ll=long long;
ll N;

const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
int n,m;
int ans=0;

vector<vector<int>> grid;
vector<ll> H, S;
vector<bool> seen;
vector<ll>sum;
vector<int> pl;

int main(int argc, char **argv){
	int n; cin>>n;
	vector<P> robo(n);

	rep(i,0,n){
		ll xi,li;cin>>xi>>li;
		robo[i]=make_pair(xi+li,xi-li);
	}

	sort(all(robo));

	ll ans=1;
	ll bord=robo[0].first;

	rep(i,1,n){
		if(robo[i].second>=bord){
			bord=robo[i].first;
			ans++;
		}
	}

	cout<<ans<<endl;
}
