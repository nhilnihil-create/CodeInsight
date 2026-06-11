#include <bits/stdc++.h>
#define ll long long
#define ar array
#define nl '\n'
#define AC ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
const int M = 1e9+7;
const int N = 2*1e5;



int main(){
    AC
    string s;
    cin>>s;
    ll ans = 0;
    ll res = 0;
    ll p = 1;
    map<ll, int> freq;
    for(int i=s.size()-1; i>=0; i--){
        res = (res + (s[i]-'0')*p)%2019;
        ans+=freq[res];
        if(res==0)
            ans++;
        freq[res]++;
        p = (p*10)%2019;
    }
    cout<<ans<<endl;
}