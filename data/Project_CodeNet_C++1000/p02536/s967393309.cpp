#include <bits/stdc++.h>
typedef long long       ll;
#define PI                acos(-1)
#define pb                push_back
#define mp                make_pair
#define mt                make_tuple
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define F first
#define S second
#define fore(i,b,e)		  for(int i=(int)b;i<(int)e;++i)
#define forr(i,b,e)		  for(int i=(int)b;i<(int)e;++i)
#define deb(x)			  cerr << "# " << (#x) << " = " << (x) << endl;
#define sz(x)             (int)x.size()
int faster_in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -faster_in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;

typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
const int INF = 1234567890;

const int tam = 1e5 + 10;

int P[tam];

int findParent(int v) {
    if (P[v] == -1) return v;
    return P[v] = findParent(P[v]);
}

int comps;

void join(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a == b) return;
    P[a] = b;
    comps--;
}

int main()
{
    std::ios::sync_with_stdio(false); cin.tie(0);
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    clr(P, -1);
    int n, m;
    cin >> n >> m;
    comps = n;
    fore(i, 0, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        join(a, b);
    }
    cout << comps-1 << '\n';
    return 0;
}
// Dinosaurs are cool!