#include <iostream>
#include <cassert>
#include <algorithm>
#define N 2000
using namespace std;
typedef pair<int,int>P;
long long f[N+1][N+1]={0};
P d[N];
int main(int argc,char ** argv)
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i){cin>>d[i].first;d[i].second=i;}
    sort(d,d+n,[](P& a,P& b)->bool{return a.first>b.first;});

    for(int i=0;i<=n;++i){
        for(int j=0;j+i<=n;++j){
            f[i][j]=+max((i>0?f[i-1][j]+(long long)d[i+j-1].first*abs(i-1-d[i+j-1].second):0),(j>0?f[i][j-1]+(long long)d[i+j-1].first*abs(n-j-d[i+j-1].second):0));
        }
    }
    long long ans=0;
    for(int i=0;i<=n;++i){
        ans=max(ans,f[i][n-i]);
    }
    cout<<ans<<endl;

    return 0;
}