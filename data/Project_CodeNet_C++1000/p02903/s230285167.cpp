#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define M (998244353)
#define INF 1e16
typedef long long ll;
typedef pair<int,int> P;
 

int  A(int x){
    if(x>=0)return x;
    else return -x;
}

int ans[1010][1010];

int main(void){
    int h,w,a,b;
    cin>>h>>w>>a>>b;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            ans[i][j]=0;
        }
    }
    for(int i=0;i<b;i++){
        for(int j=0;j<a;j++)ans[i][j]=1;
    }
    for(int i=b;i<h;i++){
        for(int j=a;j<w;j++){
            ans[i][j]=1;
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(j==w-1)cout<<ans[i][j]<<endl;
            else cout<<ans[i][j];
        }
    }
    return 0;
}