/*                         _
                        _ooOoo_
                       o8888888o
                       88" . "88
                       (| -_- |)
                  .'  \\|     |//  `.
                 /  \\|||  :  |||//  \
                /  _||||| -:- |||||_  \
                |   | \\\  -  /'| |   |
                | \_|  `\`---'//  |_/ |
                \  .-\__ `-. -'__/-.  /
              ___`. .'  /--.--\  `. .'___
           ."" '<  `.___\_<|>_/___.' _> \"".
          | | :  `- \`. ;`. _/; .'/ /  .' ; |
          \  \ `-.   \_\_`. _.'_/_/  -' _.' /
===========`-.`___`-.__\ \___  /__.-'_.'_.-'================

                  Please give me AC.
*/
#include<bits/stdc++.h>
#define mem(a) memset(a,0,sizeof(a))
#define INF 0x3f3f3f3f
#define Min 1e-6
#define lowbit(x) ((x)&(-x))
#define ls rt<<1
#define rs rt<<1|1
#define ll int

using namespace std;

const int N = 1e6 + 7;
const int M = 1e9 + 7;
const ll Mod = 2;

int i,j,n,m,t,T,p,l,r,q,len,len1,v,u,k,w,st,res,cnt,ans,tmp,nex,a[N],c[5];
string s;

int eo(int m,int n)
{
    if(!(m&(n-m))) return 1;
    else return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    mem(c);
    cin >> n;
    cin >> s;
    for(i = 1;i < n;i++){
        a[i] = abs(s[i-1]-s[i]);
        c[a[i]]++;
    }
    if(n == 2){
        cout << a[1];
        return 0;
    }
    if(!c[1]){
        ans = 0;
        for(i = 1;i < n;i++)
            if(a[i]) ans += eo(i-1,n-2);
        cout << (ans%2)*2;
    }
    else{
        ans = 0;
        for(i = 1;i < n;i++)
            if(a[i] == 1) ans += eo(i-1,n-2);
        cout << ans%2;
    }
    return 0;
}

