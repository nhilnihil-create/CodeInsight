#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9+1;

int main(){
    int n;
    cin>>n;
    int cnt[n]={};
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        cnt[a-1]++;
    }
    int ans[n]={};
    priority_queue<int> q;
    for(int i=0;i<n;i++){
        if(cnt[i]>0){
            q.push(-cnt[i]);
        }
    }
    for(int i=q.size();i>=1;i--){
        int p=ans[i-1]=-q.top();
        q.pop();
        if(i==1)break;
        while(p>0){
            p--;
            int r=q.top();
            q.pop();
            q.push(r-1);
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<endl;
    }
}
