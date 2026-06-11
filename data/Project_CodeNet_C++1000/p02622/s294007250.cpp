#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define RREP(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
typedef long long ll;



int main(void){
    string s,t;
    cin >> s >> t;
    int cnt=0;
    REP(i,(int)s.size()){
        if(s[i]!=t[i])
            cnt++;
    }

    cout << cnt << endl;
    return 0;
}