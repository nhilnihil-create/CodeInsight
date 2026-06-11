#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;(i)--)
#define rrep1(i,n) for(int i=((int)(n));i>0;(i)--)
#define sz(c) ((int)(c).size())
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pa;
typedef pair<int, pair<int, int> > PP;
const int MAX=1e5+10;

int N;
int P[MAX];
int ord[MAX];
void input(){
	cin>>N;
	rep1(i, N){
		cin>>P[i];
		ord[P[i]]=i;
	}
}

void solve(){
	multiset<int> ms;
	ms.insert(0);
	ms.insert(0);
	ms.insert(N+1);
	ms.insert(N+1);

	ll ans=0;
	rrep1(i, N){
		ms.insert(ord[i]);
		int a, b, c, d;
		auto itr1 = ms.find(ord[i]);
		auto itr2 = ms.find(ord[i]);
		itr1--;
		b = *itr1;
		itr1--;
		a = *itr1;
		itr2++;
		c = *itr2;
		itr2++;
		d = *itr2;
		ans+= (ll)i * ((b-a)*(c-ord[i])+(ord[i]-b)*(d-c));
	}
	cout<<ans<<endl;
	
}

void output(){
  
}

int main(){
  input();
  solve();
  output();
}