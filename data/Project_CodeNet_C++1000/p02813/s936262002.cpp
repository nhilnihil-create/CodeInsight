#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn= 5e5+5;
#define mod 1000000007
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
vector<array<ll,2>> adj[mxn];
bool vis[mxn];
ll ans=0,w,check;
ll dfs(int i, ll temp, int j){
    vis[i]=true;
    ll sum=0;
    for(auto x : adj[i]){
        if(!vis[x[0]]){
            if(temp+x[0]>=check*j){
                while(x[1]>=check){
                    ans++;
                    x[1]=x[1]/2;
                }
            }
            ll k=dfs(x[0],temp+x[1],j+1);
            sum=sum+k-x[1];
            if(k>=check*j){
               while(x[1]>=check){
                    ans++;
                    x[1]=x[1]/2;
                }
            }
            sum=sum+x[1];
        }
    }
    return sum;
}
int main(){
    int n;
    cin>>n;
    vector<int> vec,a,b;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        b.push_back(x);
        vec.push_back(i+1);
    }
    int cnt=1;
    int x,y;
    x=y=0;
    while(next_permutation(vec.begin(),vec.end())){
        if(a==vec){
            x=cnt;
        }
        if(b==vec){
            y=cnt;
        }
        cnt++;
    }
    cout<<abs(x-y);
}

