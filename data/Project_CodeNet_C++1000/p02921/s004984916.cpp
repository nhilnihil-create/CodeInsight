#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(int argc, const char * argv[]) {



    cin.tie(0);
    ios::sync_with_stdio(false);

    /////////////////////
    // Write code below /
    /////////////////////
    char S[3],T[3];int cnt=0;

    rep(i,3){
        cin>>S[i];
    }
    rep(i,3){
        cin>>T[i];
        if(S[i]==T[i])cnt++;
    }

    cout<<cnt<<endl;

    return 0;
}