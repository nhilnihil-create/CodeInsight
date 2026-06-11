#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>

const int INF = 0x3f3f3f3f;
const ll  LINF = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 1e5+10;
const int mod = 1e9+7;

using namespace std;

set<string> vals;
ll ans[maxn];

ll s_to_ll(string s){
    ll v=0,base=1LL;
    int n = s.size();
    for(int i=n-1;i>=0;--i){
        v+=((s[i]-'0')*base);
        base*=10LL;
    }
    return v;
}

bool ok(string s){
    return s_to_ll(s) <= 3234566667LL;
}

void generate(string curr){
    if(vals.count(curr) || !ok(curr)) return;
    vals.insert(curr);
    for(char i='0';i<='9';++i){
        string next = curr;
        next.pb(i);
        int prev = curr.back()-'0';
        if(abs(prev-(i-'0'))<=1){
            generate(next);
        }
    }
}

void solve(){
	int k;
    cin >> k;
    cout << ans[k-1] << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;

    // cin >> t;

    generate("1");
    generate("2");
    generate("3");
    generate("4");
    generate("5");
    generate("6");
    generate("7");
    generate("8");
    generate("9");

    int i=0;

    for(auto x:vals){
        ans[i++] = s_to_ll(x);
    }

    sort(ans,ans+i);

    while(t--){
    	solve();
    }

    return 0;
}