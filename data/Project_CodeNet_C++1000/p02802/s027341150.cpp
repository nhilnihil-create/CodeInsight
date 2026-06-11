#include <bits/stdc++.h>
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
#define mod 1000000007
#define pie 3.14159265358979323846264338327950L
#define N 200009
#define M 1e6+9
#define mid(l, r) l + (r - l) / 2
#define vec vector<int>
#define vecl vector<ll>
#define umap unordered_map<ll,ll>
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define endl "\n"
#define int long long
using namespace std;

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};  
int ddx[8]={1,1,0,-1,-1,-1,0,1},ddy[8]={0,1,1,1,0,-1,-1,-1};
ll gcd(ll a,ll b){ if(!a)return b;return gcd(b%a,a);}
ll lcm(ll a, ll b) { return (a*b)/ gcd(a,b);}




void test_case() {
	
    int n, m;
    cin>>n>>m;

    unordered_map<int,int> corr, wron;

    int a =0;
    int b=0;


    rep(i,m) {
        int x;
        cin>>x;

        string s;
        cin>>s;

        if(s == "AC") {
            if(corr[x] == 0) {
                a++;
                b+= wron[x];
                corr[x] = 1;
            }
        } else {
            wron[x]++;
        }
    }


    cout<<a<<" "<<b<<endl;

   




}


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed<<setprecision(20);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);


    int t = 1;
    // cin >> t;
    while(t--)
    {   
        test_case();
    }
}