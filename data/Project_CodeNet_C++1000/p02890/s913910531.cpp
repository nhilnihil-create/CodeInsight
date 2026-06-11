#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=303;
const ll INF=1LL<<50;

int main(){
    
    int N;cin>>N;
    vector<ll> pre(N),sum(N+1,0);//cnt...i個出てきたのがいくつあるか
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        a--;
        pre[a]++;
    }
    
    sort(all(pre));
    reverse(all(pre));
    
    for(int i=N-1;i>=0;i--) sum[i]=sum[i+1]+pre[i];
    
    int nowsee=0;
    for(int q=1;q<=N;q++){
        ll nowsee=0,nowtake=q;
        if(nowtake*pre[nowsee]<=sum[nowsee]){
            cout<<sum[nowsee]/nowtake<<endl;
        }else{
            ll left=nowsee,right=q-1;
            while(right-left>1){
                ll mid=(left+right)/2;
                if((nowtake-mid)*pre[mid]<=sum[mid]) right=mid;
                else left=mid;
            }
            cout<<sum[right]/(nowtake-right)<<endl;
        }
        /*while(nowtake&&nowsee<N&&nowtake*pre[nowsee]>sum[nowsee]){
            nowsee++;
            nowtake--;
        }
        if(nowsee==N) cout<<0<<endl;
        else cout<<sum[nowsee]/nowtake<<endl;*/
        //else cout<<min(pre[nowsee-1],sum[nowsee]/nowtake)<<endl;
    }
    
}



