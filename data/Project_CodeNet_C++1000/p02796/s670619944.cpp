#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
constexpr int di[] = { 0, 1, 0, -1 }, dj[] = { 1, 0, -1, 0 };
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define SORT(v) sort((v).begin(), (v).end())
#define SORTR(v) sort((v).rbegin(), (v).rend())
#define all(v) (v).begin(), (v).end()
#define vmax 10000
constexpr ll inf = 1e18+7;
/*cout<<fixed<<setprecision(20);cin.tie(0);ios::sync_with_stdio(false);*/

int n;
vector<int> a;

ll gcd(ll a,ll b){
    if(b==0){
        return a;
    }else{
        return gcd(b,a%b);
    }
}

bool check(int mid){
  
  return false;
}

ll serch(ll ok,ll ng){
	while (abs(ok-ng) > 1) {
		ll mid = (ok + ng) / 2;
		if (check(mid))ok = mid;
		else ng = mid;
	}
	return ok;
}

int main(){
  cout<<fixed<<setprecision(20);cin.tie(0);ios::sync_with_stdio(false);
  int n;
  cin>>n;
  int x,y;
  int ans=1;
  priority_queue<P> l;
  rep(i,n){
    cin>>x>>y;
    l.push(make_pair(x-y,x+y));
  }
  int tmp=l.top().first;
  while(!l.empty()){
    if(l.top().second<=tmp){
      tmp=l.top().first;
      ans++;
    }
    l.pop();
  }
  cout<<ans<<endl;
  return 0;
}
