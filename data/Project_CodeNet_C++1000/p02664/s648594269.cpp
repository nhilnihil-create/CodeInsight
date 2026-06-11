#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, m, n) for(int i = m; i < n; i++) 
#define mod 1000000007
#define pi 3.1415926535
typedef long long ll;
int main(){
    string T;
    cin>>T;
    
    rep(i,T.size()-1){
        if(T[i]=='?'&&T[i+1]=='?'){
            T[i]='P';
            T[i+1]='D';
        }else if(T[i]=='P'&&T[i+1]=='?'){
            T[i+1]='D';
        }else if(T[i]=='?'&&T[i+1]=='D'){
            T[i]='P';
        }
    }

    rep(i,T.size()){
        if(T[i]=='?'){
            T[i]='D';
        }
    }
    
    cout<<T<<endl;
    
    return 0;
}