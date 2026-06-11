#include<bits/stdc++.h>
#define _USE_MATH_DEFINES
using namespace std;
 
#define ll long long int
#define pb push_back
#define rep(i , j , n) for(ll i = j ; i < n ; i++)
#define per(i , j , n) for(ll i = j ; i >= n ; i--)
#define all(x) x.begin(), x.end()
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vll;

int main(){
    ll n,k;
    cin >> n >> k;
    ll j = 0;
    vll a(n),b(n);
    rep(i,0,n){
        cin >> a[i];
        b[i] = 0;
    }
    while(j < k && j <= 42){
        j++;
        rep(i,0,n){
            ll l,r;
            l = max((ll)0,i - a[i]);
            r = min(n - 1, i + a[i]);
            b[l]++;
            if(r + 1 < n) b[r + 1]--;
        }
        rep(i,0,n){ 
            if(i > 0) b[i] += b[i - 1];
            a[i] = b[i];
        }
        rep(i,0,n){
            b[i] = 0;
        }

    }
    rep(i,0,n){
        cout << a[i] << " ";
    }
    
}