#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define mm(arr) memset(arr, 0, sizeof(arr))
#define scanArray(a,n) for(int i = 0; i < n; i++){cin >> a[i];}
#define pb push_back
#define PI 3.141592653589793
#define MOD 1000000007
using namespace std;
int main(){
    FAST
    ll n; cin >> n;
    string s[n];
    vector<string>vec;
    for(ll i=0;i<n;i++){
        cin >> s[i];
        sort(s[i].begin(), s[i].end());
        vec.pb(s[i]);
    }
    map<string,ll>mpp;
    sort(vec.begin(),vec.end());
    ll cnt=0;
    ll j=1;
    map<string,ll>mpp2;
    for(ll i=0;i<n;i++){
        mpp2[s[i]]=1;
    }
    for(ll i=0;i<n;i++){
        mpp[s[i]]++;
        if(mpp[s[i]]>1){
            cnt+=mpp2[s[i]];
            mpp2[s[i]]++;
        }
    }
    cout << cnt << endl;






    return 0;
}
