#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define pb push_back
#define mpr make_pair
#define pii pair<int, int>
#define ll long long
#define ld long double
#define all(arr) arr.begin(), arr.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define fo(i, l, r) for (int i = l; i <= r; i++)
#define MOD 1000000007
#define mod 998244353
#define pie 3.14159265358979323846264338327950L
#define N 200009
#define M 2000009
#define mid(l, r) l + (r - l) / 2
#define vec vector<int>
#define umap unordered_map<int, int>
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
#define endl "\n"
#define int long long
using namespace std;
 
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};  
int ddx[8]={1,1,0,-1,-1,-1,0,1},ddy[8]={0,1,1,1,0,-1,-1,-1};
ll gcd(ll a,ll b){ if(!a)return b;return gcd(b%a,a);}
ll lcm(ll a, ll b) { return (a*b)/ gcd(a,b);}
 

bool fun(string temp, string s) {
    string ans = temp+temp;
    return ans == s;
}




void test_case() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    bool check = false;

    string temp ="";

    for(int i=0; i<n-1; i++) {
        temp+=s[i];
        if(n%temp.size() == 0 && fun(temp,s)) {
            // cout<<i<<endl;
            check = true;
        }
    }
    if(check) {
        yes;
    } else {
        no;
    }
     
}
    

signed main ()
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