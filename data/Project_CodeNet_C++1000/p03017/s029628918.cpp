#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;
const int MOD = 1000000007;

/* --------------------------------------------------- */
bool solve(void){
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    --a;
    --b;
    --c;
    --d;
 
    string s;
    cin >> s;
 
    forr(i, a, c){
        if(s[i] == '#' && s[i + 1] == '#'){
            return false;
        }
    }
    forr(i, b, d){
        if(s[i] == '#' && s[i + 1] == '#'){
            return false;
        }
    }
 
    if(c < d){
        return true;
    }
 
    forr(i, b, d + 1){
        if(s[i - 1] == '.' && s[i] == '.' && s[i + 1] == '.'){
            return true;
        }
    }
 
    return false;
}
 
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
 
    if(solve()){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
 
    return 0;
}