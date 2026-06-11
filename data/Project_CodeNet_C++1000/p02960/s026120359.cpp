#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI pair<int,int>
const int maxm=1e5+5;
const int mod=1e9+7;
int d[maxm][13];
char s[maxm];
int n;
signed main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    if(s[1]!='?'){
        d[1][s[1]-'0']=1;
    }else{//d[1]=='?'
        for(int j=0;j<10;j++){
            d[1][j]=1;
        }
    }
    for(int i=2;i<=n;i++){
        if(s[i]!='?'){
            int x=s[i]-'0';
            for(int j=0;j<13;j++){
                int t=(j*10+x)%13;
                d[i][t]+=d[i-1][j];
                d[i][t]%=mod;
            }
        }else{
            for(int x=0;x<10;x++){
                for(int j=0;j<13;j++){
                    int t=(j*10+x)%13;
                    d[i][t]+=d[i-1][j];
                    d[i][t]%=mod;
                }
            }
        }
    }
    cout<<d[n][5]<<endl;
    return 0;
}
/*

*/
