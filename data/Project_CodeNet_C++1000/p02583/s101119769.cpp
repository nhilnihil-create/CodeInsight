#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e9+7;
const int N = 2e5+5;


vector<ll>ans,veca,vecb;
vector<int>adj[N];
vector<double>aka;
vector<pair<int,double>>dp[N];
vector<bool>vis;


void init(int n){
    ans.clear();veca.clear();aka.clear();vis.clear();ans.resize(n);
    vecb.clear(),vecb.resize(n);veca.resize(n);vis.resize(n);
    for (int i = 0; i <n; i++) {
        vis[i]=0;
    }
    for (int i = 0; i<=n; i++) {
        adj[i].clear();
    }
    for (int i = 0; i <=n; i++) {
        dp[i].clear();
    }
    for (int i = 0; i < n; i++) {
        ans[i]=0;
    }
}

int check(int arr[]){
    sort(arr,arr+3);
    if(arr[0]==arr[1]||arr[1]==arr[2]||arr[2]==arr[0]) return 0;
    int res=0;
    if(arr[0]+arr[1]>arr[2]) res=1;
    return res;
    
}
bool valid(int a,int b,int c){
    if((a<b)&&(b<c)) return 1;
    return 0;
}
void solve(){
    int n,flag=0;
    cin>>n;
    init(n);
    for (int i = 0; i <n; i++) {
        cin>>veca[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if(valid(i,j,k)){
                    int arr[3];
                    memset(arr,0,sizeof(arr));
                    arr[0]=veca[i];arr[1]=veca[j];arr[2]=veca[k];
                    flag+=check(arr);
                }
            }
        }
    }
    cout<<flag<<"\n";
    
}

int main(){
   
   
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
        
        
    return 0;
}