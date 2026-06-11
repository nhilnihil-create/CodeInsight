#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<long long , long long>
#define pb push_back
#define ll long long
#define ld long double
#define precision(x,d) cout<<fixed<<setprecision(d)<<x
#define fill(a,b) memset((a),(b),sizeof((a)))
#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL));
ll power(ll x,ll y,ll m){ll r=1;for(;y;y>>=1){if(y&1)r=r*x%m;x=x*x%m;}return r;}
const ll mod = 1e9 + 7;
const ld pi = 3.14159265358979;
    
int get(int n){
    string s = to_string(n);
    return s[0] - '0';
}

int run_test(){
    int n;
    cin>> n;
    int arr[10][10];
    for(int i=0; i<10; i++){
        for(int j =0; j < 10; j++){
            arr[i][j] = 0;
        }
    }
    for(int i=1; i<=n; i++){
        int r = i % 10;
        int l = get(i);
        arr[l][r]++;
    }
    ll ans = 0;
    for(int i=1; i<10; i++){
        for(int j =1; j< 10; j++){
            ans += arr[i][j] * arr[j][i];
        }
    }
    cout << ans;
    return 0;

}
    
int main(){
   FAST;
    ll t;
    t = 1;
     
    while(t--){
        run_test();
    }
}