#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
using P = pair <int, int>;
 
ll MOD = 1000000007;
ll INF =1<<29;

int main() {
    int n,l;
    cin >> n >> l;
    vector<int> a(n+1);
    int tot =0;
    rrep(i,n){
        a[i]= l+i-1;
        tot +=a[i];
    }
    int MIN = 210;
    int ans;
    rrep(i,n){
        if(abs(a[i])<MIN){
            MIN =abs(a[i]);
            ans = i;
        }
    }
    cout << tot-a[ans]<<endl;

}