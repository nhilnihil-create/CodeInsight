#include <bits/stdc++.h>
 
using namespace std;
 
#define rep(i, n) for(int i=0; i<(n); i++)
#define FOR(i, m, n) for(int i=(m);i<(n);i++)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define SORT(x) sort((x).begin(),(x).end())
#define REVE(x) reverse((x).begin(),(x).end())
#define mp make_pair
#define pb push_back
#define chmax(x,y) x = max(x,y)

 
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<vector<int> > VVI;
typedef pair<int, int> PII;
typedef long long LL;
typedef vector<bool> VB;
typedef vector<LL> VL;
typedef vector<vector<long long>> VVLL;
const int MOD = 1e9+7;
const int INF = 1e9;
const LL LINF = 1e18;
int gcd(int a, int b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}

int lcm(int a, int b)
{
   return a * b / gcd(a, b);
}

int main() {
    int n,k,c;
    cin >> n >> k >> c;
    string s;
    cin >> s;

    VI wpfront(n+2);
    VI wpback(n+2);
    VI wp;
    rep(i,s.length()) {
        if(s[i] == 'o') {
            wp.push_back(i+1);
        }
    }

    int cnt = 0;
    int prev = 0;
    rep(i,s.length()) {
        if(s[i]=='o' && i>=prev) {
            cnt++;
            wpfront[i+1] = cnt;
            prev = i+c+1;
        } else {
            wpfront[i+1] = cnt;
        }
    }
    prev = s.length();
    cnt = 0;
    for(int i = s.length()-1;i>=0;i--) {
        if(s[i] == 'o' && i <= prev) {
            cnt++;
            wpback[i+1] = cnt;
            prev = i - c -1;
        } else {
            wpback[i+1] = cnt;
        }
    }

    VI ans;
    for(auto i:wp) {
        if(wpfront[i-1] + wpback[i+1] < k) {
            ans.push_back(i);
        }
    }

    for(auto i:ans) {
        cout << i << endl;
    }

}
