#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define COUT(x) cout<<(x)<<"\n"

int main(){
    int n;string s;
    cin >> n >> s;
    int r=0,w=0;
    REP(i,n){
        if(s[i]=='R')r++;
        else w++;
    }
    int r2=r;
    REP(i,r){
        if(s[i]=='R'){
            r2--;
        }
    }
    COUT(min({r,w,r2}));
}
