#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    cout << fixed << setprecision(10);
    int n,a,b,c,d;
    cin >> n >> a >> b >> c >> d;
    string s;
    cin >> s;
    a--; b--; c--; d--;
    for(int i = a; i < max(c,d); i++){
        if(s[i+1]=='#' && s[i]=='#'){
            cout << "No" << endl;
            return 0;
        }
    }
    if(c < d){
        cout << "Yes" << endl;
        return 0;
    }else{
        for(int i = b-1; i <= d-1 ; i++){
            if(s[i] == '.' && s[i+1] == '.' && s[i+2] == '.'){
                cout << "Yes" << endl;
                return 0;
            }
        }
        cout << "No" << endl;
        return 0;
    }
    return 0;
}