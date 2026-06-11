#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;
ll mod = 1000000007;
ll inf = 1e18;
int main(){

    ll a,b,n;
    cin >> a >> b >> n;

    if(n<b){
        cout << a*n/b << endl;
    }else{
        cout << a*(b-1)/b << endl;
    } 
    
    return 0;
}