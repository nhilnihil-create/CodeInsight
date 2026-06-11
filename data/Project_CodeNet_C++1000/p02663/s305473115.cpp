#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=(s);i<(n);i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define REPR(i,s,n) for(int i=(s);i>=(n);i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define pb push_back
#define pf push_front
const int mod = 1e9 + 7;
const int INF = 1e9;
const double pi = acos(-1.0);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
int main(){
    ll h1, h2, m1, m2, k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    ll time = h2*60 + m2 - h1*60 - m1;
    //cout << time << endl;
    cout << time - k << endl;

    return 0;
}  