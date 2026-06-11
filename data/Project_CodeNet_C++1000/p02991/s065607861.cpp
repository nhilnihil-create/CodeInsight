#include <bits/stdc++.h>
/* S.size() s.substr(l,r=s.size()-l) -> l文字目からr文字分
__gcd()　lower_bound(a+l,a+r,x)-a でindex
配列  -> min/max({}) 
vector-> *min_element(a.begin()+l,a.begin()+r)  *忘れず lとrで[l,r) 
reverse(a+l,a+r)   配列aの[l,r)を逆順に strはreverse(all(s))
sort(a+l,a+r,greater <int>()) 配列aの[l,r)昇順sort,大きい順はgreater<type>()
clock()/CLOCKS_PER_SEC で秒数 int ti=clock() ok
q.push(x),front()で先頭を返す,pop()で削除, size(),empty()
<deque>(push/pop)_(front/back)/fornt/back/insert/
priority_queue 宣言は priority_queue< Type, vector<Type>, greater<Type>> Q1; 
pq.push(x),top()で参照 pop()で削除   greaterで最小 lessで最大がtopに*/
using namespace std;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define range(i, s, n) for (int i = (s); i < (n); ++(i))
#define lange(i, s, n) for (long long i = (s); i < long long (n); ++(i))
#define rrep(i,n) for(int (i)=(n)-1;(i)!=-1;--(i))
#define vep(i,v) for(auto (i)=v.begin();distance((i),(v.end()))>0;++(i))
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline T GCD(T a, T b) { return b?GCD(b,a%b):a;}
template<class T> inline T LCM(T a, T b) { return a/GCD(a,b)*b;}
inline long long ceildiv(long long a, long long  b) { return (a+b-1)/b; }
template<class T> inline T modinv(T a, T M) { return (1-M*modinv(M%a,a))/a+M;}
typedef pair<long long,long long> P;
typedef pair<int,long long> Pil;

typedef pair<int,int> PI;
typedef std::vector<int> vi;
typedef std::vector<long long> vl;
typedef std::vector<std::vector<int>> vvi;
typedef std::vector<std::vector<long long>> vvl;
typedef std::vector<char> vc;
typedef std::vector<std::vector<char>> vvc;
typedef std::vector<long long> vl;
typedef std::vector<bool> vb;
typedef std::vector<std::vector<bool>> vvb;
using Graph = std::vector<std::vector<int> >;
const long long inf = 10e17;
const long long mod = 1000000007;
//int |x|<=2*10**9     long |x|<= 9*10**18
//printf(".(小数点以下の桁数)lf(double時、float ならf)")
#define ll long long
#define print(i) std::cout << (i) << '\n'
#define eb emplace_back
int main(){

int n,m,s,t;cin>>n>>m;
vvi e(3*n+3,vi{});
int x,y;
rep(i,m){cin>>x>>y;x*=3;y*=3;
e[x].eb(y+1);
e[x+1].eb(y+2);
e[x+2].eb(y);}
queue<pair<int,ll>> q;
cin>>s>>t;s*=3;t*=3;
vl dist(3*n+5,-1);
dist[s]=0;
q.push(Pil(s,0));
while(!q.empty()){
    auto p=q.front();q.pop();
    int now=p.first;ll cost=p.second;
    if (t==now){print(cost/3);return 0;}
  	++cost;
    for(auto next:e[now]){if (dist[next]==-1){q.push(Pil(next,cost));dist[next]=cost;}}

}
print(-1);}
