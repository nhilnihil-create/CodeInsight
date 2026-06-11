#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define ll long long
const long long INF = 1LL<<60;
const long long mod = 100000007;
using Graph = vector<vector<int>>;

int main(){
    int A,B;
    cin >> A >> B;
    int ans = -1;
    for(int p = 1; p < 2000;++p){
        int a = p*2;
        a/=25;
        int b = p/10;
        if(a==A&&b==B){
            ans = p;
            break;
        }
    }
    cout << ans << endl;
}