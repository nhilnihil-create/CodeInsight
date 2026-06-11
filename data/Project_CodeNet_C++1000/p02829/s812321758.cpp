#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define ll long long
const long long INF = 1LL<<60;
const long long mod = 1e9 + 7;

int main(){
    int A,B;
    cin >> A >> B;
    int ans;
    REP(i,3){
        if(i!=A-1 && i != B-1) ans = i;
    }
    ans++;
    cout << ans << endl;
}