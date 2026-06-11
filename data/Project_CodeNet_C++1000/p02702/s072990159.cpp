#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define div 2019

ll rem[2019];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;

    ll cur = 0;
    ll stha = 1;

    ll pairr = 0;

    for(ll i = s.size()-1; i >= 0; i--){
        ll temp = s[i]-48;
        temp *= stha;
        cur += temp;

        ll t_rem = cur%div;
        if(t_rem == 0) pairr++;
        pairr += rem[t_rem];
        rem[t_rem]++;

        stha *= 10;

        stha %= div;
        cur %= div;

    }

    cout<<pairr<<'\n';


    return 0;
}
