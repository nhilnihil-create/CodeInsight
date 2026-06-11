#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll gcd(ll a, ll b) {return (!b ? a : gcd(b, a % b));}

const ll mod = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const ld pi = 3.141592653589793;

void solve(){
     string s;
     cin >> s;
     int cnt = 1;int maxi = 1;
     int n = s.length();
     vector<int>a(n,1);
     for(int i = 0;i<n-1;i++){
        if(s[i]==s[i+1]&&s[i]=='R') {cnt++; a[i+1] += a[i];a[i] = 0;}
     }
     for(int i = n-1;i>=1;i--){
        if(s[i]==s[i-1]&&s[i]=='L'){a[i-1]+=a[i];a[i] = 0;}
     }

     for(int i = 0;i<n-1;i++){
        if(a[i]){
            int sum = a[i]+a[i+1];
            maxi = max(a[i],a[i+1]);
            if(sum%2){
                if(a[i]>a[i+1]){a[i] = sum/2+1;a[i+1] = sum/2;}
                else {a[i+1] = sum/2+1;a[i] = sum/2;}
                if(maxi%2==0) swap(a[i],a[i+1]);
            }
            else{
                a[i] = sum/2;a[i+1] = sum/2;
            }
            i++;
        }
     }

     for(int i = 0;i<n;i++) cout << a[i] <<' ';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    solve();
    return 0;
}
