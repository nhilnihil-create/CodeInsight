#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793
#define MOD 1000000007
typedef long long ll;
typedef long double ld;

#define rep(i, n) for (int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()

int main() {
    string s;
    cin >> s;
    ll n=s.size();
    vector<ll>num(n,0);
    for(ll i=0;i<n-1;i++){
        if(s[i]=='R'&&s[i+1]=='L'){
            for(ll j=i;j>=0&&s[j]=='R';j--){
                num[i+((i-j)%2)]++;
            }
            for(ll j=i+1;j<n&&s[j]=='L';j++){
                num[i+((j-i)%2)]++;
            }
        }
    }
    for(ll i=0;i<n;i++){
        cout << num[i] << " ";
    }
}