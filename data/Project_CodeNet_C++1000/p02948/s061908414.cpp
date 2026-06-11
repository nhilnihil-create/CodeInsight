#include<bits/stdc++.h>
#define vll vector<ll>
#define vi vector<int>
#define vpll vector<pair<ll,ll>>
#define pii pair<int,int>
#define REP(i,a) for(int (i)=0; (i)<(a); (i)++)
#define RREP(i,a) for(int (i)=a-1; (i)>=(0); (i)--)
#define REP2(i,a,b) for(int (i)=(a); (i)<(b); (i)++)
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define m0(x) memset(x,0,sizeof(x))
typedef long long ll;

using namespace std;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M, a, b; cin >> N >> M;
  vector<vector<int>> p(M + 100);
  REP(i,N){
    cin >> a >> b;
    if(a <= M) p[a].push_back(b);
  }
  int day = 1, ans = 0; // M - day日目にするバイトを決めたい
  priority_queue<int> q;
  for(int day = 1; day <= M; day++){ 
  	for(int b : p[day]){
    	q.push(b);
    }
    if(!q.empty()){
	    ans += q.top();
    	q.pop();
    }
  }
  cout << ans;

  return 0;
}