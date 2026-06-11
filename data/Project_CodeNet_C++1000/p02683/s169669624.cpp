#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int INF=1e9;
const ll MOD=1e9+7;

ll dp[100100];
ll sum[100100];
bool used[100100];


int main(){
    int N,M,X; cin >> N >> M >> X;
    int c[N];
    int a[N][M];
    for(int i=0;i<N;i++){
        cin >> c[i];
        for(int j=0;j<M;j++){
            cin >> a[i][j];
        }
    }
    int ans=INF;
    for(int bit=0;bit<(1<<N);bit++){
        int res=0;
        int sum[M]={};
        for(int i=0;i<N;i++){
            if((1<<i)&bit){
                res+=c[i];
                for(int j=0;j<M;j++){
                    sum[j]+=a[i][j];
                }
            }
        }
        bool flag=true;
        for(int i=0;i<M;i++){
            if(sum[i]<X) flag=false;
        }
        if(flag){
            ans=min(ans,res);
        }
    }
    if(ans==INF){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
    
}