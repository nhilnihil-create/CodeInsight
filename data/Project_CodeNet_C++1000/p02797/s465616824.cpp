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


int main(void){
    int n,k,s;
    cin>>n>>k>>s;
    vector<int>ans(n);
    if(s>n-k){
        for(int i=0;i<n;i++){
            if(k>0){
                ans[i]=s;
                k--;
            }
            else ans[i]=1;
        }
    }
    else{
        for(int i=0;i<n;i++){
            if(k>0){
                ans[i]=s;
                k--;
            }
            else ans[i]=1000000000;
        }
    }
    for(int i=0;i<n;i++){
        if(i==n-1)cout<<ans[i]<<endl;
        else cout<<ans[i]<<" ";
    }
    return 0;
}