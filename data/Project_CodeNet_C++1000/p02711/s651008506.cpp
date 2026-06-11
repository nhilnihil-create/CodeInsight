#include<bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;
typedef pair<int, int> P;
#define rrep(i,a,b) for(int i=a;i>=b;i--)

signed main(){
    string s;
    cin >> s;
    rep(i, 3){
        if(s[i] =='7'){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}