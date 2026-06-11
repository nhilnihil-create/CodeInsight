#include <bits/stdc++.h>
#define ll long long int
#define F first
#define S second
const ll mod = 1e9 + 7;
const ll INF = 922337203685477;
#define pb push_back
#define deb(x) cout << '>' << #x << ':' << x << endl;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;
int main()
{
    fastio;
    string s,t;
    cin>>s>>t;
    ll c=0;
    for(ll i=0;i<s.length();++i){
        if(s[i]==t[i]) ++c;
    }
    cout<<c;
    return 0;
}
