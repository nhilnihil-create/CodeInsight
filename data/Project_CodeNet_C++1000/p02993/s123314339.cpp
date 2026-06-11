#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(int argc, const char * argv[]) {



    cin.tie(0);
    ios::sync_with_stdio(false);

    /////////////////////
    // Write code below /
    /////////////////////
    string S;

    cin>>S;

    if(S[0]==S[1]||S[1]==S[2]||S[2]==S[3]){
        cout<<"Bad"<<endl;
    }
    else{
        cout<<"Good"<<endl;
    }


    return 0;
}
