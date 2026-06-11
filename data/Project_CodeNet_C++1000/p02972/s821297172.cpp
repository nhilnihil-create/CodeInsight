#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=998244353;

int main(void){
    int n;
    cin>>n;
    vector<int> A(n);
    rep(i,n) cin>>A[i];
    vector<int> ans(n,-1);
    int m=0;
    for(int i=n;i>0;--i){//上から決めていく
        int count=0;//i以外のiの倍数のうちボールが入ってる個数
        for(int j=2;j<=n;++j){
            if(i*j>n) break;
            if(ans[i*j-1]==-1){
                puts("error");
                return 0;
            }
            count+=ans[i*j-1];
        }
        if(count%2==A[i-1])
            ans[i-1]=0;
        else{
            ans[i-1]=1;
            m++;
        }
    }
    cout<<m<<endl;
    rep(i,n) if(ans[i]==1) cout<<i+1<<" ";
    cout<<endl;
    return 0;
}