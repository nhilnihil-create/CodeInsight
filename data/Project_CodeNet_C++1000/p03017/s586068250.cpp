#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef long double ld;
typedef pair <ll ,ll> pll;
typedef pair <int ,int> pii;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define print(a) {for (auto iiiiiiiiii : a) cout << iiiiiiiiii << ' '; cout << '\n';}
#define fi first
#define se second
#define all(x) (x).begin() , (x).end()

ll next() {ll x; cin >> x; return x;}

const ll inf = 1e18 , mod = 998244353;
const int intf = 2e9 , maxn = 1e5;
const double PI = 3.141592653589 , eps = 1e-8;

int n;
string s;

void dfs(int v , vector <bool> &was){
    was[v] = true;
    if (v + 1 < n && !was[v + 1] && s[v + 1] != '#') dfs(v + 1 , was);
    if (v + 2 < n && !was[v + 2] && s[v + 2] != '#') dfs(v + 2 , was);
}

void revdfs(int v , vector <bool> &was){
    was[v] = true;
    if (v - 1 >= 0 && !was[v - 1] && s[v - 1] != '#') revdfs(v - 1 , was);
    if (v - 2 >= 0 && !was[v - 2] && s[v - 2] != '#') revdfs(v - 2 , was);
}

void rint(bool a , bool b){
    if (a && b){
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    exit(0);
}

void solve(){
    int a , b , c , d;
    cin >> n >> a >> b >> c >> d;
    a-- , b-- , c-- , d--;
    cin >> s;

    vector <bool> cana(n , false) , canb(n , false) , canc(n , false) , cand(n , false);
    dfs(a , cana);
    dfs(b , canb);
    revdfs(c , canc);
    revdfs(d , cand);

    if (c < d){
        rint(cana[c] , canb[d]);
    }

    for (int i = 0; i + 2 < n; i ++){
        if (s[i] == '.' && s[i + 1] == '.' && s[i + 2] == '.'){
            if (cana[i] && canb[i + 1] && cand[i + 1] && canc[i + 2]) rint(true , true);
            if (cana[i + 1] && canb[i] && cand[i + 2] && canc[i + 1]) rint(true , true);
        }
    }
    rint(false , false);
}

int main()
{
    #ifdef HERE
        freopen("input.txt" , "r" , stdin);
    #else
        //freopen(".in" , "r" , stdin); freopen(".out" , "w" , stdout);
        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #endif
    cout.precision(20);

    int t = 1;
    while(t --> 0){
        solve();
    }


    #ifdef HERE
        cout << setprecision(3) << fixed << "\n\nRuntime: " << (long double)(clock()) / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
/*

*/
