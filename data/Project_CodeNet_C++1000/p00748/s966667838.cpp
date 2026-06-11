#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int dp[1000001],Odp[1000001];
int Tn[200],OTn[200]; 

int main(){
    int count = 0;  //pollocks numberの生成
    for(int i = 1;i < 200;i++){
        Tn[i-1] = i * (i + 1) * (i + 2) / 6;
        if(Tn[i-1] % 2 == 1){
            OTn[count] = Tn[i-1];
            count++;
        }
    }
    int n = 1000000;

    //正四面体数の個数の最小値
    for(int j = 0;j <= n;j++)
        dp[j] = j;
    int k;
    for(int i = 0;i < 200;i++)
        for(int j = Tn[i];j <= 1000000;j++){
            if(j >= Tn[i])
                dp[j] = min(dp[j],dp[j-Tn[i]] + 1);
            k = i;
        }

    //奇数正四面体数の個数の最小値
    for(int j = 0;j <= n;j++)
        Odp[j] = j;
    int k1;
    for(int i = 0;i <= 200;i++)
        for(int j = OTn[i];j <= n;j++){
            if(j >= OTn[i])
                Odp[j] = min(Odp[j],Odp[j-OTn[i]] + 1);
            k1 = i;
        }
    while(cin >> n,n)
        cout << dp[n] << ' ' <<  Odp[n] << endl;


    return 0;
}
