#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define pb push_back
#define mpr make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ll long long
#define ld long double
#define all(arr) arr.begin(), arr.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define fo(i, l, r) for (int i = l; i <= r; i++)
#define INF 1000000001
#define inf1 1000000000000000001
#define mod 1000000007
#define pie 3.14159265358979323846264338327950L
#define N 100005
#define mid(l, r) l + (r - l) / 2
#define vec vector<int>
#define vecl vector<ll>
#define umap unordered_map<ll,ll>
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
#define endl "\n"
using namespace std;
 
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};  
int ddx[8]={1,1,0,-1,-1,-1,0,1},ddy[8]={0,1,1,1,0,-1,-1,-1};
ll gcd(ll a,ll b){ if(!a)return b;return gcd(b%a,a);}




 
    
void test_case() {

    int n, k;
    cin>>n>>k;

    vecl arr(k);
    rep(i,k) {
        cin>>arr[i];
    }

    sort(all(arr));

    ll ans = n;
    ll d1, d2;
    for(int i=0; i<k; i++) {
        if(i==0) {
            d1 = 0;
            d2 = arr[0] - arr[1]; 
        } else if(i==k-1) {
            d1 = arr[k-1] - arr[k-2];
            d2 = 0;
        } else {
            d1 = arr[i] - arr[i+1];
            d2 = arr[i] - arr[i-1];
        }

        ans = min(ans, n - abs(d1));
        ans = min(ans, n- abs(d2));

        // if(ans == 5) {
        //     cout<<i<<endl;
        // }
    }

     ans = min(ans, arr[k-1] - arr[0]);

    cout<<ans<<endl;


}
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed<<setprecision(20);
 
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
 
 
    int t = 1;
    // cin >> t;
    while (t--)
    {
        test_case();
    }
}