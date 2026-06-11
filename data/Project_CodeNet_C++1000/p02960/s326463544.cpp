#include <bits/stdc++.h>
using namespace std;
#define int long long
using vec_int = vector<int>;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int charToInt(char c){
    char zero_num = '0';
    return (int)c - (int)zero_num;
}

signed main(){
    string S;cin>>S;
    int length = S.size();

    int MOD = pow(10,9) + 7;

    // 
    int amari[length+1];
    amari[1] = 1;
    for(int i=2;i<length+1;i++){
        amari[i] = (amari[i-1]*10)%13;
    }

    // いわゆる桁DPで片が付く
    int DP[length+1][13];
    for(int i=0;i<13;i++){
        for(int j=0;j<length+1;j++){
            DP[j][i]=0;
        }
    }

    DP[0][0] = 1;

    for(int i=1;i<length+1;i++){
        if(S.at(length-i)=='?'){
            for(int j=0;j<13;j++){
                for(int k=0;k<10;k++){
                    DP[i][(j+amari[i]*k)%13]  = (DP[i][(j+amari[i]*k)%13] +DP[i-1][j])%MOD;
                }
            }
        }else{
            int val = charToInt(S.at(length-i));
            for(int j=0;j<13;j++){
                DP[i][(val*amari[i]+j)%13]  = DP[i-1][j];
            }
        }
    }
    cout<<DP[length][5]<<endl;




    return 0;
}