#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;
ll mod = 1000000007;
ll inf = 1e18;
int main(){

    int x;
    cin >> x;
    ll a,b;
    bool ans=false;

    for(a=-120; a<=120; a++){
        for(b=-120; b<=120; b++){
            if(a*a*a*a*a-b*b*b*b*b==x){
                cout << a << ' ' << b << endl;
                ans=true;
                break;
            }
        }
        if(ans) break;
    }
    
    return 0;
}