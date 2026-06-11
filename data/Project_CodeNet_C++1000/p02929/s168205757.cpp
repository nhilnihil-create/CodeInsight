//#include <bits/stdc++.h>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define pb push_back
#define ll long long
#define pi 3.1415926
using namespace std;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef pair<long long,int> pli;
typedef pair<int,long long> pil;
const int INF=1000000007;
const int MOD=1000000007;
const int nmax=201234;

int n;
ll res;
char s[nmax];

int main()
{
    scanf("%d",&n);
    scanf("%s",s);
    if(s[0]=='B'){
        int cnt=1;
        int flg=0;
        res=1;
        for(int i=1; i<2*n; ++i)
        {
            if(s[i]==s[i-1])
                flg^=1;
            if(flg==1){
                res=res*cnt%MOD;
                if(cnt==0)
                    break;
                --cnt;
            }
            else{
                ++cnt;
            }
        }
        if(cnt!=0)
            res=0;
        else if(res!=0)
            for(int i=2;i<=n;++i)
                res=res*i%MOD;
    }
    printf("%lld\n",res);
    return 0;
}
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
