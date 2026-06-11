#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const int MAX = 100000;
static const int NIL = -1;
using namespace std;

ll calC(ll a, ll b){

    if(a == 1) return 0;
    ll ans = 1;
    ll tmpB = b;
    ll tmpA = a;
    for(int i = 1; i <= b; i ++){
        ans *= tmpA;
        tmpA --;
    }
    for(int i = 1; i <= b; i ++){
        ans /= tmpB;
        tmpB --;
    }

    return ans;
}
int main() {
    int n,a,b,c,d; cin >> n >> a >> b >> c >> d;
    vector<char> ch(n+1,'.');
    string ans = "No";
    rep(i,n) cin >> ch[i];

    for(int i = a; i < d; i ++){
        if(ch[i] == '#' && ch[i+1] == '#') {
            cout << "No";
            return 0;
        }
    }
    
    if(c < d){
        ans = "Yes";
        for(int i = a; i < d; i ++){
            if(ch[i] == '#' && ch[i+1] == '#') ans = "No";
        }
        cout << ans ;
        return 0;
    }

    for(int i = b-1; i < d; i ++){
        if(ch[i-1] == '.' && ch[i] == '.' && ch[i+1] == '.'){
            ans = "Yes";
        }
    }
    
    cout << ans;


    return 0;
}
