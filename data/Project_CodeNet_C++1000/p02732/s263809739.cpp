#include <bits/stdc++.h>

using namespace std;
using Graph = vector<vector<int>>;
using Grid= vector<vector<char>>;
using vin= vector<int>;
using ll=long long;
using vll= vector<ll>;
using vbl=vector<bool>;
using vch=vector<char>;
using pinin=pair<int ,int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rell(i,n) for (ll i=0; i< (ll)(n); i++)
#define sort(x) sort(x.begin(), x.end());
#define rese(x) reverse(x.begin(), x.end());
#define vnn(x,y,name) vector<vector<int>> name(x, vector<int>(y));

string yes="Yes",no="No";

int main() {
    int n;
    cin>>n;
    vin a(n);
    vin cnt(n);
    rep(i,n){
        cin>>a[i];
        cnt[a[i]-1]++;
    }
    ll sum=0;

    rep(i,n){
        sum+=(ll)cnt[i]*((ll)cnt[i]-1)/2;
    }
    rep(i,n){
        cout<<sum-(ll)cnt[a[i]-1]+1<<endl;
    }
    
}
