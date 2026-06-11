#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<ld> vd;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<vector<ll>> vvll;
typedef vector<pair<ll, ll>> vpll;
typedef priority_queue<ll, vector<ll>, greater<ll>> spqll;  // 小さい順に取り出し
typedef priority_queue<ll, vector<ll>, less<ll>> bpqll;     // 大きい順に取り出し

#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define IREP(i, v) for (auto i = (v).begin(); i != (v).end(); i++)
#define FI first
#define SE second
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define TS to_string
#define NP next_permutation
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) (ll) x.size()
#define SP(x) setprecision((ll)x)


ll INF = 1e9;
ll MOD = 1000000007;
ll LINF = 1e18;
ld EPS = 1e-9;
ld PI = M_PI;
vll dx = {1, 0, -1, 0, 1, -1, -1, 1};
vll dy = {0, 1, 0, -1, 1, 1, -1, -1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;} //最大公約数
ll lcm(ll a, ll b) { return a / gcd(a, b) * b;}     //最小公倍数

void yes(){ cout << "yes" << endl;}
void no(){ cout << "no" << endl;}

//-----------------------------------------
template<class T>
class BT{
  private:
    struct Node{
      T key;
      Node *par, *lef, *rig;
    };
    Node *NIL, *root;
  public:
    BT(){
      NIL = NULL;
    }
    void insert(T k){
      Node *y = NIL;
      Node *x = root;
      Node *z;

      z = (Node*)malloc(sizeof(Node));
      z->key = k;
      z->lef = NIL;
      z->rig = NIL;

      while(x != NIL){
        y = x;
        if(k < x->key) x = x->lef;
        else x = x->rig;
      }
      z->par = y;
      if(y == NIL) root = z;
      else if(z->key < y->key) y->lef = z;
      else y->rig = z;
    }

    bool finding(T k, Node *t){
      if(t == NIL) return false;
      if(t->key == k) return true;
      if(k < t->key) return finding(k,t->lef);
      else return finding(k,t->rig);
    }
    bool find(T k){
      return finding(k,root);
    }

    void pmid(Node *t){
      if(t == NIL) return;
      pmid(t->lef);
      cout << " " << t->key;
      pmid(t->rig);
    }

    void ppre(Node *t){
      if(t == NIL) return;
      cout << " " << t->key;
      ppre(t->lef);
      ppre(t->rig);
    }

    void pr(){
      pmid(root);
      cout <<endl;
      ppre(root);
      cout <<endl;
    }
};
//-----------------------------------------

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  BT<int> tree;
  REP(i,n){
    string s;
    cin >> s;
    if(s == "insert"){
      int a;
      cin >> a;
      tree.insert(a);
    }
    else if(s == "find"){
      int a;
      cin >> a;
      if(tree.find(a)) yes();
      else no();
    }
    else{
      tree.pr();
    }
  }



  return 0;
}




