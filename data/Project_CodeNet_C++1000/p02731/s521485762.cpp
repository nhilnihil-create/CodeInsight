#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define VI vector<int>
#define PII pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define db double
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)x.size())
mt19937 mrand(random_device{}());
const ll mod = 1000000007;
int rnd(int x){return mrand()%x;}
clock_t ac; double TLE(){return (double)(clock()-ac)/CLOCKS_PER_SEC;}
void DBG() {cerr << "]" << endl;}
template<class H, class... T> void DBG(H h, T... t) {
cerr << to_string(h);
if(sizeof...(t)) cerr << ", ";
DBG(t...);}
#ifdef _DEBUG
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif
int maxvalue(int s){
  int len = s/3.0;
  s-=len;
  if(len==0)len=1.0;
  int breadth = s/2.0;
  int height = s-breadth;
  if(breadth==0) breadth=1.0;
  return len*breadth*height;
}

int main(){
 ios::sync_with_stdio(0);
 cin.tie(0);
 double n;
 cin>>n;
 double res= n/3;
 cout<<fixed<<setprecision(6)<<res*res*res<<"\n";
}
