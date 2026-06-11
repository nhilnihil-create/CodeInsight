#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
int main(){
    ll a;
    string b;
    cin >> a >> b;
    ll c = (b[0]-'0')*100 + (b[2]-'0')*10 + (b[3]-'0');  
    cout << (a*c)/100 ;

    return 0;
}