#include <bits/stdc++.h>
#include <limits>
using namespace std;
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define lli long long int
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define um unordered_map
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define mem(data_structure, val) memset(data_structure, val, sizeof(data_structure))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define endl "\n"
const ll mod = 1e9+7;
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vll;
typedef vector<pii>		vpii;
typedef vector<pll>		vpll;
typedef vector<vi>		vvi;
typedef vector<vll>		vvll;

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 
um<pii, int, hash_pair> map_with_pair{};
priority_queue <int, vector<int>, greater<int> > pq_desc; // decreasing order


int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
  
	lli n, d;
	cin >> n >> d;
	cout << ceil(n*1.0/(2*d+1)) << endl;
	return 0;
}