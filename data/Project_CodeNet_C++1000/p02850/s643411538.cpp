#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vint;
typedef vector<double> vdbl;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<vector<int> > vvint;
typedef vector<pair<int, int> > vpii;
typedef vector<pair<ll, ll> > vpll;
typedef priority_queue<int, vector<int>, greater<int> > spqint; //小さい順に取り出し
typedef priority_queue<ll, vector<ll>, greater<ll> > spqll;     //小さい順に取り出し
typedef priority_queue<int, vector<int>, less<int> > bpqint;    //大きい順に取り出し
typedef priority_queue<ll, vector<ll>, less<ll> > bpqll;        //大きい順に取り出し

#define REP(i, n) for (int(i) = 0; (i) < (int)(n); i++)
#define FOR(i, a, b) for (int(i) = a; (i) < (int)b; i++)
#define IREP(i, v) for (auto i = v.begin(); i != v.end(); i++)
#define MOD 1000000007
#define NIL -1
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define PF push_front
#define TS to_string
#define BS binary_search
#define LB lower_bound
#define UB upper_bound
#define NP next_permutation
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) (ll) x.size()
#define SP(x) setprecision((ll)x)

const int INF = 1e9;
const ll LINF = 1e18;
const double EPS = 1e-9;
const double PI = M_PI;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; } //最大公約数
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }     //最小公倍数

void yes()
{
    cout << "Yes" << endl;
}
void no()
{
    cout << "No" << endl;
}
//-----------------------------------------
int V, E ;
vector<int> color ;
vector<int> seen ;
vector<int> dist ;
vector<vector<int> > graph ;
queue<int> que ;
//-----------------------------------------
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> V ;
    E = V - 1 ;


    vector<int> zero(V,0) ;
    seen = zero ;
    dist = zero ;
    color = zero ;

    for(int i=0;i<V;i++){
        graph.push_back(vector<int>()) ;
    }

    vector<pair<int,int>> pai(E) ;

    for(int i=0;i<E;i++){
        int a, b ;
        cin >> a >> b ;
        graph[a-1].push_back(b-1) ;
        graph[b-1].push_back(a-1) ;
        pai[i] = MP(a-1,b-1) ;
    }

    que.push(0) ;
    seen[0] = 1 ;
    color[0] = 0 ;

    while(!que.empty()){
        int k = que.front() ;
        que.pop() ;
        int aa = 1 ;
        for(int i=0;i<graph[k].size();i++){
            if(seen[graph[k][i]]==0){
                que.push(graph[k][i]) ;
                seen[graph[k][i]] = 1 ;
                while(1){
                    if(aa!=color[k]){
                        color[graph[k][i]] = aa ;
                        aa++ ; 
                        break ;
                    }
                    aa++ ;
                }
            }
        }
    }

    vint vec = color ;
    sort(ALL(vec)) ;
    cout << vec[V-1] << endl ;
    REP(i,E){
        cout << color[pai[i].SE] <<endl ;
    }

    

    return 0;
}
