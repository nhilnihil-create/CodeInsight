#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back 
#define mp make_pair
#define f first
#define s second
#define sz(x) ((int)x.size())
const ll maxint=2e18;
const ll minint =-2e18;
/*******\
(͡ ° ͜ʖ ͡ °) : Hello there, relax.
\*     */

int main(){
    string s;
    cin>>s;
    if(s == "RRR"){
        cout<<3<<'\n';

    }else if(s=="SSS"){
        cout<<0<<'\n';
    }else if(s[1]=='R'){
        if(s[0]=='R' || s[2]=='R'){
            cout<<2<<'\n';
        }else 
        cout<<1<<'\n';
    }else{
        cout<<1<<'\n';
    }
    return 0;
}