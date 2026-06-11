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
    if(s[sz(s)-1] == 's'){
        cout<<s<<"es\n";
    }else cout<<s<<"s\n";
    return 0;
}