#include <bits/stdc++.h>  

#define int long long 
#define ull unsigned long long int
#define M (int)(1e9+7)
#define for0(i, n) for (int i = 0; i < (int)(n); i++) // 0 based indexing
#define for1(i, n) for (int i = 1; i <= (int)(n); i++) // 1 based indexing
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); i++) // closed interver from l to r r inclusive
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; i--) // reverse 0 based.
#define forr1(i, n) for (int i = (int)(n); i >= 1; i--) // reverse 1 based


#define pb push_back
#define fi first
#define se second


#define all(x) (x).begin(), (x).end() 
#define rall(x) (x).rbegin, (x).rend() 
#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define sz(a) int((a).size())


using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef double ld;

//-------------------------------------------------------------------------------END----------------------------------------------------------------------------------//
int mod(int x){
    return ((x%M + M)%M);
}

int add(int a,int b){
    return mod(mod(a)+mod(b));
}

int mins(int a,int b){
    return mod(mod(a)-mod(b));
}

int mul(int a,int b){
    return mod(mod(a)*mod(b));
}

int modpower(int x, unsigned int y)  {  
    if(y==0)return 1;
    if(y==1)return x%M;

    int res=1;
    while(y){
        if(y%2==1)res=mul(res,x);
        x = mul(x,x);
        y = y/2;
    } 
    return res;
}

int factorial(int n){ 
    return (n==1 || n==0) ? 1: n * factorial(n - 1);  
} 

bool inc(vi vec){
    for1(i,vec.size()-1){
        if(vec[i]<vec[i-1])return 0;
    }
    return 1;
}





void solve(){
    string s;cin>>s;

    cout<<s.substr(0,3);
}





int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //cout.precision(10);
    //cout << fixed;
    //int tt;cin>>tt;
    //while(tt--){
        solve();
    //}
    return 0;
}

