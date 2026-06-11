#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;

int main(){
    string s;
    cin >> s;
    ll n = s.size();
    vector<ll>right(n+1);
    vector<ll>left(n+1);
    right[n]=0;
    left[0]=0;
    for(ll i = 1;i <= n;i++){
        if(s[i-1]=='<')left[i]=left[i-1]+1;
        else left[i]=0;
    }
    for(ll i = n-1;i>=0;i--){
        if(s[i]=='>')right[i]=right[i+1]+1;
        else right[i]=0;
    }
    ll ans = 0;
    for(ll i = 0;i<n+1;i++){
        ans += max(right[i],left[i]);
        //cout << right[i] << " " << left[i] << endl;
    }
    cout << ans << endl;
    return 0;
}