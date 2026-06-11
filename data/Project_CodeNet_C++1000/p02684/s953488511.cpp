#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;
ll mod = 1000000007;
ll inf = 1e18;
int main(){

    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n+1);
    vector<bool> t(n+1);
    rep2(i,1,n+1) cin >> a[i];
    ll r,s,c=1;
    map<int,int> mp;
    vector<int> town;

    rep(i,n+1){
        if(t[c]){
            s=mp[c];
            r=i-s;
            break;
        }else{
            mp[c]=i;
            t[c]=true;
            town.push_back(c);
            c=a[c];
        }
    }
    if(k<s) cout << town[k] << endl;
    else{
        k-=s;
        k%=r;
        cout << town[s+k] << endl;
    // cout << s << ' ' << r << ' ' << k << endl;
    }
    
    return 0;
}