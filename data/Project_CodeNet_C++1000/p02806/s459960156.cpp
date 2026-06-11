/*Lower_Rating*/
/*Dwango Programming Contest 6th A*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<stack>
#include<vector>
#include<queue>
#include<bitset>
using namespace std;

#define LL long long
#define DB double
#define MOD 998244353
#define Pr pair<DB,int>
#define X first
#define Y second
#define MAXN 50
#define INF 20000000000000000LL
#define mem(x,p) memset(x,p,sizeof(x))

LL read(){
  LL x=0,F=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')F=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
  return x*F;
}

int add(int a,int b){return (a+b>=MOD)?a+b-MOD:a+b;}
int dec(int a,int b){return (a-b<0)?a-b+MOD:a-b;}
int mul(int a,int b){return 1LL*a*b%MOD;}

int n,t[MAXN+5],F,res;
string s[MAXN+5],x;

int main()
{
    n=read();
    for(int i=1;i<=n;i++)
        cin>>s[i],t[i]=read();
    cin>>x;
    for(int i=1;i<=n;i++){
        if(F)res+=t[i];
        if(x==s[i])F=1;
    }
    printf("%d\n",res);
}
