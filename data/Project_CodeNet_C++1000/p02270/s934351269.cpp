#include <numeric>
#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include <cstdio>
#include<algorithm>
#include <sstream>
#include<string>
#include<string.h>
#include <cmath>
#include <iomanip>
#include <string>
#include<list>
using namespace std;
#define int long long
#define inf 1000000007
#define rep(i,j,n) for(int i=j;i<n;i++)
typedef pair<int,int>  P;
struct edge{int to,cost;};
double pi = 3.141592653589793;
//使うやつはここから下に置こうな
int n,k,w[114514];
bool check(int num){
    int count=1;
    int wei=0;
    rep(i,0,n){
        if(wei+w[i]<=num)wei+=w[i];
        else {
            count++;
            wei=w[i];
        }
    }
    return count<=k;
}
signed main(){
    cin>>n>>k;
    int maxi=0;
    rep(i,0,n){
        cin>>w[i];
        maxi=max(maxi,w[i]);
    }
    int li=maxi-1,ans=inf;
    while(ans-li>1){
        int mid=(ans+li)/2;
        if(check(mid))ans=mid;
        else li=mid;
    }
    cout<<ans<<endl;
    return 0;
}
