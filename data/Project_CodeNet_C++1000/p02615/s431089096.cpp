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
    vector<int> v;
    REP(i,n){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(RALL(v));
    ll ans=0;
    FOR(i,1,n){
        ans+=v[i/2];
    }
    cout << ans << endl;
    return 0;
}