#include<cstdio>
#include<iostream>
using namespace std;
int n,s,ans=0;
class SumofIntegers{
public:
    void solve(){
        dfs(0,0,0);
        cout<<ans<<endl;
        ans=0;
    }
    void dfs(int d,int sum,int idx){
        if(d==n){
            if(sum==s)ans++;
            return;
        }
        for(int i=idx;i<10;i++)dfs(d+1,sum+i,i+1);
    }
};
int main(){
    SumofIntegers inst;
    while(cin>>n>>s){
        if(n==0&&s==0)break;
        inst.solve();
    }
}