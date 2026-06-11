#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#define pb push_back
#define mpr make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ll long long
#define ld long double
#define fi first
#define se second
#define all(arr) arr.begin(), arr.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define fo(i, l, r) for (int i = l; i <= r; i++)
#define INF 1000000001
#define inf1 1000000000000000001
#define MOD 1000000007
#define mod 1000000007
#define pie 3.14159265358979323846264338327950L
#define N 200009
#define M 1e6 + 9
#define mid(l, r) l + (r - l) / 2
#define vec vector<int>
#define vecl vector<ll>
#define umap unordered_map<ll, ll>
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
#define endl "\n"
#define int long long
using namespace std;

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};  
int ddx[8]={1,1,0,-1,-1,-1,0,1},ddy[8]={0,1,1,1,0,-1,-1,-1};
ll gcd(ll a,ll b){ if(!a)return b;return gcd(b%a,a);}
ll lcm(ll a, ll b) { return (a*b)/ gcd(a,b);}





void test_case()
{

    int n, m;
	cin >> n >> m;
	vector < int > a(n);
	set < int > s;	
	for(int &i : a) {
		cin >> i;
		i /= 2;
		int cur = i,cnt = 0;
		while(cur % 2 == 0) {
			cur /= 2;
			cnt++;
		}
		s.insert(cnt);
	}
	if(s.size() > 1) {
		cout << 0 << endl;
		return ;
	}
	int lcm = a[0];
	for(int &i : a) {
		lcm = (i * lcm) / gcd(lcm, i);
		if(lcm > m) {
			cout << 0 << endl;
			return ;
		}
	}
	int ans = m / lcm;
	ans = (ans + 1) / 2;
	cout << ans << endl;


    




    
    
    
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        test_case();
    }
}