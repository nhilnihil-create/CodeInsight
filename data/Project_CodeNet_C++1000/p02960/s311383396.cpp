#include <bits/stdc++.h>
using namespace std ;
typedef long long ll;

int main(){
    string s;cin>>s;
    ll mod1=1e+9 +7;
    int mod=13;
    int length = s.length();
    ll d[length+1][13];
    for(int i=0;i<13;i++){
        for(int j=0;j<=length;j++) d[j][i]=0;
    }
    int beki=1;
    //for(int i=0;i<10;i++) d[length][i]=1;
    d[length][0]=1;

    for(int i=length;i>0;--i){
        char a = s.at(i-1);
        if(a=='?'){
            for(int j=0;j<13;j++){
                for(int k=0;k<10;k++){
                    d[i-1][(beki*k+j)%mod]+=d[i][j];
                    d[i-1][(beki*k+j)%mod]%=mod1;
                }                
            }
        }
        else{
            int c =s[i-1]-'0';
            for(int j=0;j<13;j++){

                d[i-1][(beki*c+j)%mod]+=d[i][j];
                d[i-1][(beki*c+j)%mod]%=mod1;

            }
        }


        beki = beki*10%mod;

    }
    cout << d[0][5]<<endl;
}