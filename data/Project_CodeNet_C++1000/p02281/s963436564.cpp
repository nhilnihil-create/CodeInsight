#include <vector>
#include <math.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <deque>
#include <map>

typedef long long ll;
#define rep(i, a, n) for(int i = a; i<n; i++)
#define ALL(a) begin(a), end(a)
#define mii map<int, int>
#define msi map<string, int>
#define vi vector<int>
#define vl vector<ll>
#define MOD 1000000007
#define INF 1e9
#define showVector(v) rep(i,0,v.size()){p(v[i]);p(" ")} pl("")
#define p(s) std::cout << s ;
#define pl(s)  std::cout << s << endl;
using namespace std;

#define NIL -1
struct Node {
    int parent;
    int left;
    int right;
};

Node T[100001];
int D[100001];
int H[100001];
int getSibling(int u) {
    if (T[u].parent == NIL) return NIL;
    if (T[T[u].parent].left != u && T[T[u].parent].left != NIL) {
        return T[T[u].parent].left;
    }
    if (T[T[u].parent].right != u && T[T[u].parent].right != NIL) {
        return T[T[u].parent].right;
    }
    return NIL;
}
void print(int i) {
    cout << "node " << i << ": ";
    cout << "parent = " << T[i].parent;
    cout << ", sibling = " << getSibling(i);

    // 子の数
    int deg = 0;
    if (T[i].left != NIL) deg++;
    if (T[i].right != NIL) deg++;
    cout << ", degree = " << deg;

    //別配列で管理して求めていることがめちゃくちゃ覚えにくいというか、よくわからない。
    //とりあえずそれで丸暗記。

    // setDepthで別配列ですでに求めている
    cout << ", depth = " << D[i];

    // setHeightで別配列ですでに求めている
    cout << ", height = " << H[i];

    // rootの定義、leafの定義、internalの定義
    if (T[i].parent == NIL) {
        cout << ", root" << endl;
    } else if (T[i].left == NIL && T[i].right == NIL) {
        cout << ", leaf" << endl;
    } else {
        cout << ", internal node" << endl;
    }
}

void preParse(int u) {
    if (u == NIL) return;
    cout << " ";
    cout << u;
    preParse(T[u].left);
    preParse(T[u].right);
}

void inParse(int u) {
    if (u == NIL) return;
    inParse(T[u].left);
    cout << " ";
    cout << u;
    inParse(T[u].right);
}

void postParse(int u) {
    if (u == NIL) return;
    postParse(T[u].left);
    postParse(T[u].right);
    cout << " ";
    cout << u;
}

void setDepth(int u, int d) {
    if (u == NIL) return;
    D[u] = d;
    setDepth(T[u].left, d+1);
    setDepth(T[u].right, d+1);
}

int setHeight(int u) {
    int h1 = 0;
    int h2 = 0;
    if (T[u].left != NIL) {
        h1 = setHeight(T[u].left) + 1;
    }

    if (T[u].right != NIL) {
        h2 = setHeight(T[u].right) + 1;
    }
    return H[u] = max(h1, h2);
}


int n;
int main() {
    int v, l, r, root = 0;
    
    //節点の個数
    cin >> n;
    rep(i, 0, n) {
        T[i].parent = NIL;
    }
    rep(i, 0, n) {
        cin >> v >> l >> r;
        T[v].left = l;
        T[v].right = r;
        if (l != NIL) {
            T[l].parent = v;
        }
        if (r != NIL) {
            T[r].parent = v;
        }
    }
    rep(i, 0, n) {
        if (T[i].parent == NIL) {
            root = i;
        }
    }
    cout << "Preorder" << endl;
    preParse(root);
    cout << endl;
    cout << "Inorder" << endl;
    inParse(root);
    cout << endl;
    cout << "Postorder" << endl;
    postParse(root);
    cout << endl;

    return 0;
}
