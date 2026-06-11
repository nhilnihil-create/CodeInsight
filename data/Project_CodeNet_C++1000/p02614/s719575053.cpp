#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define RREP(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int H,W;
int K;
char c[6][6+1];

int main(void){
    cin >> H >> W >> K;
    REP(i,H){
        REP(j,W){
            cin >> c[i][j];
        }
    }

    int ans=0;

    for(int bith=0;bith<(1<<H);bith++){
        for(int bitw=0;bitw<(1<<W);bitw++){
            int black=0;
                REP(i,H){
                    REP(j,W){
                        if(((bith>>i)&1)==0 && ((bitw>>j)&1)==0 && c[i][j]=='#')
                            black++;  
                    }
                }
            if(black==K)
                ans++;
        }
    }
    
    cout << ans << endl;

    return 0;
}