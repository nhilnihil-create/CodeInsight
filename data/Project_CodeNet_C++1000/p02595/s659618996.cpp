#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define RREP(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;



int main(void){
    int n,d;
    cin >> n >> d;
    int ans=0;
    REP(i,n){
        double x,y;
        cin >> x >> y;
        if(sqrt(x*x+y*y)<=d)
            ans++;
    }
    cout << ans << endl;

    return 0;
}