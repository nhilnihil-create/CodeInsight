#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX

#include <bits/stdc++.h>

using namespace std;

#define db(x) cout << (x) << '\n';
#define all(x) x.begin(),x.end()
#define UNIQUE(x) sort(all(x)),x.resize(unique(all(x))-x.begin())
#define LB(v,x) lower_bound(all(v),x)
#define UB(v,x) upper_bound(all(v),x)
#define endl "\n"
#define F first
#define S second
#define PB push_back
#define PF push_front
#define int long long
#define double long double
#define trick int m = (l+r)>>1,lc=n<<1,rc=lc|1

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;

int dy[]={0,1,1,1,0,-1,-1,-1};
int dx[]={-1,-1,0,1,1,1,0,-1};
const int maxn = 1e5;
const int OO = 1e18;
const int mod = 1e9 + 7;
const double PI = acos(-1);

void maxself(int &a,int b)
{a=max(a,b);}
void minself(int &a,int b)
{a=min(a,b);}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n,m;
	cin >> n >> m;
	vector<bool>mk(n+1,0);
	vi WA(n+1,0);
	int ac=0,wa=0;
	for(int i=0;i<m;i++)
    {
        int p;
        string s;
        cin >> p >> s;
        if(s == "AC")
        {
            mk[p] = true;
        }
        else if(mk[p] == false)
        {
            WA[p]++;
        }
    }
    for(int i=0;i<=n;i++)
        if(mk[i]==true)
        ac++,wa+=WA[i];
    cout << ac << ' ' << wa;
	return 0;
}

