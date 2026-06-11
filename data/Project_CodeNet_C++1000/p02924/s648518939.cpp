#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define in insert
#define er erase
#define fi first
#define se second
#define mp make_pair
#define all(x) x.begin(),x.end()
#define sz(x) (int) x.size()
using namespace std;
typedef vector <int> vi;
typedef vector <vector<int>> vii;
typedef pair<int,int> pii;
typedef double db;
typedef long long ll;
typedef long double ld;

const long double PI=3.141592653589793238462643383279502884;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
int main(){
    fast;
    ll n;
    cin>>n;
    cout<<n*(n-1)/2;
    return 0;
}



