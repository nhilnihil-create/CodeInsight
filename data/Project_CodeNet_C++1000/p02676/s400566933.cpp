#include<bits/stdc++.h>
using namespace std;
#define EPS 1e-10
#define INF 1e18
#define mod 1000000007
#define PI acos(-1.0L)
#define REP(i,n) for(int i=0;i<(n);i++)
#define REPR(i,n) for(int i=n;i>0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define ALL(n) begin(n),end(n)
#include<bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
int main(void){
    int k;
    string s;
    cin >> k >>s;
    if(s.length() <= k)cout << s << endl;
    else
    {
        REP(i,k){
            cout <<s[i];
        }
        cout << "..." << endl;
    }

    return 0;
}