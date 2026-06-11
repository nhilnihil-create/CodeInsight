#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
using P = pair <int, int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
ll MOD = 1000000007;
ll INF =1<<30;



int main(){
    ll n,a,b;
    cin >> n >> a>>b;
    if((b-a)%2==0){
        cout << (b-a)/2 <<endl;
        return 0;
    }
    ll dir = max(b-1,n-a);
    ll left = (b+a-1)/2;
    ll right = (2*n-b+1-a)/2;
    //cout << dir <<endl;
    //cout << left <<endl;
    //cout <<right <<endl;
    cout << min(dir,min(left,right))<<endl;
}