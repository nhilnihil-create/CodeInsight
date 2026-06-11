#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define RREP(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
typedef long long ll;


int main(void){
    int n;
    cin >> n;
    vector<int> v(n);
    int all=0;
    REP(i,n){
        cin >> v[i];
        all^=v[i];
    }

    REP(i,n)
        v[i]^=all;

    REP(i,n)
        cout << v[i] << endl;
    return 0;
}