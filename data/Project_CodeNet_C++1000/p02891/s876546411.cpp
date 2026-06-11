#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)

int main() {
    string S;
    long long K;
    cin>>S>>K;
    string SS=S+S;
    int S_num=0;
    int SS_num=0;
    int sflug=1, ssflug=1;
    bool onazi=false;
    rep(i,S.size()-1){
        if(S[i]==S[i+1]){
            sflug++;
        }else{
            S_num+=sflug/2;
            sflug=1;
        }
    }
    if(S.size()==sflug){
        onazi=true;
    }
    S_num+=sflug/2;

    rep(i,SS.size()-1){
        if(SS[i]==SS[i+1]){
            ssflug++;
        }else{
            SS_num+=ssflug/2;
            ssflug=1;
        }
    }
    SS_num+=ssflug/2;

    long long ans = S_num+(SS_num-S_num)*(K-1);
    if(onazi){
        cout << (S.size()*K)/2<<endl;
    }else{
        cout <<ans<<endl;
    }
}
//2053-