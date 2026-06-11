#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main(){
    long long A,V,B,W,T;
    cin>>A>>V>>B>>W>>T;
    if(W>=V){
        cout << "NO" << endl;
        return 0;
    }
    long long dist = abs(A-B);
    long long sp = V-W;
    if(sp*T>=dist){
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}