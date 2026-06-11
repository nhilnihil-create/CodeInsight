
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()

int main(){
    int N;cin>>N;
    int tmp=0;
    int ans=0;
    int keta=0;
    for(int i=1;i<=N;i++){
        tmp=i;
        while(1){
            keta++;
            tmp/=10;
            if(tmp==0){
                break;
            }else{
                continue;
            }
        }
        if(keta%2==1){
            ans++;
        }
        keta=0;
    }
    cout<<ans<<endl;
}