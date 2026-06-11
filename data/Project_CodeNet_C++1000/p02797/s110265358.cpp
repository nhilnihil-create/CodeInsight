// 及时当勉励，岁月不待人！
//当前状态 : attempted
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<cmath>
#include<string>
#include<iomanip>
using namespace std;
typedef long long ll;

int inf=1e9;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
inline int read(){int ret = 0, sgn = 1;char ch = getchar();while(ch < '0' || ch > '9'){if(ch == '-')sgn = -1;ch = getchar();} while (ch >= '0' && ch <= '9'){ret = ret*10 + ch - '0';ch = getchar();}return ret*sgn;}


//结构体
//全局变量
const int maxn=1005;
//函数
int main()
{
    std::ios::sync_with_stdio(false);
    int n,m,sum;
    cin>>n>>m>>sum;
    if(inf==sum)inf--;
    if(n==m){
        for(int i=1;i<=n;++i){
            cout<<sum<<' ';
        }
        cout<<endl;
    }else{
        int tmp=n-m;
        for(int i=1;i<=tmp;++i){
            cout<<inf<<' ';
        }
        for(int i=1;i<=m;++i){
            cout<<sum<<' ';
        }
        cout<<endl;
    }
    return 0;

}