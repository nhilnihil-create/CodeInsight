#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define RREP(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
typedef long long ll;



int main(void){
    int x,n;
    cin >> x >> n;
    vector<bool> v(101+1);
    REP(i,101+1)
        v[i]=true;

    REP(i,n){
        int p;
        cin >> p;
        v[p]=false;
    }
    
    int ans=x;

    for(int i=0;i<101+1;i++){
        if(v[x-i]==true){
            ans=x-i;
            break;
        }
        if(v[x+i]==true){
            ans=x+i;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}