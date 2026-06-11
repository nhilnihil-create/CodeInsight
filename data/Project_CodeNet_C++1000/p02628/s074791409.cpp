#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define RREP(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
typedef long long ll;



int main(void){
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    REP(i,n)
        cin >> v[i];
    
    sort(ALL(v));

    int ans=0;
    REP(i,k)
        ans+=v[i];

    cout << ans << endl;
    return 0;
}