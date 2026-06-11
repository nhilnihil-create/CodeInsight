#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <iomanip>
using namespace std;
typedef long long ll;
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

#define EPS (1e-7)
#define INF (1e15)
#define PI (acos(-1))
#define MOD 1000000007

#define REP(i,n) for(int i=0;i<n;i++)
#define REPS(i,f,n) for(int i=(f);i<(n);i++)
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)

#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define arrdump(n,a) for(int i=0;i<n;i++) {cout<<((i>0)? " ":"")<<a[i];}cout<<"\n";


typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

int dy4[]={0, 0, 1, -1};
int dx4[]={1, -1, 0, 0};
int dx8[]={0, 0, 1, -1, 1, 1, -1, -1};
int dy8[]={1, -1, 0, 0, 1, -1, -1, 1};

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_7_A&lang=jp

#define MAX 1000005
#define NIL -1

int n;
struct Node
{
    int l, r, p;
};
Node T[MAX];
int D[MAX];

static void setDepth(int id, int d) {
    D[id] = d;
    if (T[id].l != NIL) setDepth(T[id].l, d+1);
    if (T[id].r != NIL) setDepth(T[id].r, d);
}

static void print(int id) {
    cout << "node " << id << ": ";
    cout << "parent = " << T[id].p << ", ";
    cout << "depth = " << D[id] << ", ";
    if (T[id].p == NIL) cout << "root, ";
    else if (T[id].l == NIL) cout << "leaf, ";
    else cout << "internal node, ";

    int cnt = 0;
    cout << "[";
    for (int c  = T[id].l; c != NIL; c = T[c].r) {
        if (cnt) cout << ", ";
        cnt++;
        cout << c;
    }
    cout << "]\n";

}


int main() {
    cin >> n;
    REP(i, n) T[i].l = T[i].r = T[i].p = NIL;
    REP(i, n) {
        int id, deg; cin >> id >> deg;
        int l = 0;
        REP(j, deg) {
            int c; cin >> c;
            if (j == 0) T[id].l = c;
            else T[l].r = c;
            l = c;
            T[c].p = id;
        }
    }

    int root = 0;
    REP(i, n) if (T[i].p == NIL) root = i;
    setDepth(root, 0);

    REP(i, n) print(i);

    return 0;
}

