#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int ctoi(char c) {return c-'0';}// char to int
int gcd(ll a,ll b){return b?gcd(b,a%b):a;}//MAX
int lcm(ll a,ll b){return a*b/gcd(a,b);}//MIN
 
int  main(){
int m,d;
cin >> m >> d;
int ans = 0;
for(int i=1;i<=m;i++){
    for(int j=10;j<=d;j++){
        int keta = 1,che=j;
        while(che>0){
            keta*=che%10;
            che/=10;
        }
        if(keta==i&&j%10>=2&&j/10>=2){ans++;}

    }
}
cout << ans << endl;
}
 
