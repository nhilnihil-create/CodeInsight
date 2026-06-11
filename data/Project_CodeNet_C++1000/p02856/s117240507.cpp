#include<iostream>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdio>
#include<sstream>
#include<vector>
#include<algorithm>
 
using namespace std;
#define read(x) scanf("%d",&x)
#define Read(x,y) scanf("%d%d",&x,&y)
#define gc(x)  scanf(" %c",&x);
#define mmt(x,y)  memset(x,y,sizeof x)
#define write(x) printf("%d\n",x)
#define pii pair<int,int>
#define INF 0x3f3f3f3f
#define ll long long
#define mod  998244353
const int N = 1e5 + 10;
const int M = 2e6 + 1005;
int main()
{
    int n;
    cin>>n;
    ll Sum = 0,num = 0;
    for(int i = 1;i <= n;++i){
        ll a,b;
        cin>>a>>b;
        Sum += a*b;
        num += b;
 
    }
    num = num - 1 + (Sum - 1) /9;
    cout<<num<<endl;
}