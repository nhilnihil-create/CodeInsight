#include<bits/stdc++.h>
#include<vector>
#define inf 1000000
#define ll unsigned long long 
#define boostUP ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fsr(i,n) for(ll i=0;i<n;i++)
#define fcr(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define sz(arr) sizeof(arr)/sizeof(arr[0])

using namespace std;

int main(){
    ll n ,a ,b, count = 0;
    cin >> n >> a >> b;
    ll sum = 0, ans = 0, rem = 0;
    cout << (n / (a+b)) * a + min(n%(a+b),a) << endl;
}


