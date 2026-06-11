#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using vi = vector<int>;
using vv = vector<vi>;

int main(void){
    string s;cin>>s;
    int n = s.size();
    vv dbl(20, vi (n));
    
    rep(i,n){
        if(s[i]=='L')
            dbl[0][i]=i-1;
        else
            dbl[0][i]=i+1;
    }
    
    rep(j,19){
        rep(i,n){
            dbl[j+1][i] = dbl[j][dbl[j][i]];
        }
    }
    
    vi seat(n, 0);
    rep(i,n){
        seat[dbl[19][i]]++;
    }
    rep(i,n){
        printf("%d%c", seat[i], i==n-1?'\n':' ');
    }
    
    return 0;
}