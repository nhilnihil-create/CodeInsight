#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define what_is(x) cerr << #x << " is " << x << endl;
#define MT make_tuple
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define FOR(i,n) for (int i=0;i < n ; i++)
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
clock_t startTime;
long double getTime(){
	return (long double)(clock()-startTime)/CLOCKS_PER_SEC;
}

ll n,q,a,b;
std::vector<ll>* edges;
ll* sum, *finalsum, *parent;
bool *touched;





int main(){
	startTime=clock();
	cin >> n >> q;
	sum=new ll[n];
	finalsum=new ll[n];
	touched=new bool[n];
	edges=new std::vector<ll> [n];
	parent=new ll[n];
	parent[0]=0;

	FOR(i,n){
		sum[i]=0;
		finalsum[i]=0;
		touched[i]=false;
	}
	FOR(i,n-1){
		cin >> a >> b;
		edges[a-1].eb(b-1);
		edges[b-1].eb(a-1); 
	}

	FOR(i,q){
		cin >> a >> b;
		sum[a-1]+=b;
	}
	

	queue<ll>qu;
	qu.push(0);
	touched[0]=true;
	while(!qu.empty()){
		ll y=qu.front();
		qu.pop();
		for(auto x : edges[y]){
			if(!touched[x]){
				touched[x]=true;
				parent[x]=y;
				qu.push(x);
			}
		}
	}

	qu.push(0);
	FOR(i,n) touched[i]=false;
	finalsum[0]=sum[0];
	touched[0]=true;
	while(!qu.empty()){
		ll y=qu.front();
		qu.pop();
		for(auto x : edges[y]){
			if(!touched[x]){
				finalsum[x]=(x!=0) ? sum[x]+finalsum[parent[x]] : sum[x];
				qu.push(x);
				touched[x]=true;
			}
		}
	}
	FOR(i,n){
		cout << finalsum[i] <<" ";
	}
	

	return 0;
}