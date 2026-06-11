#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define endl "\n"

const int MOD = 2019;

int main(){
    //
    //
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    ll ans=0;
    int n= (int) s.size();
    vector <int> mods(MOD);
    int pot = 1, suf=0;
    string sum = "";
    for (int i=n-1; i>=0; --i){
        int digit = s[i]-'0';
        suf = (suf+digit*pot)%MOD;
        if (suf==0){
            ans++;
        }
        pot = 10*pot%MOD;
        ans+= mods[suf];
        mods[suf]++;
    }
    cout<<ans<<endl;
    return 0;
}