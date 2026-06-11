#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long; 
using P=pair<int,int>;
using lP=pair<ll,ll>;
using fP=pair<double,double>;

int main(){
    int n,m;
    cin>>n>>m;
    vector<P>job(n);
    rep(i,n){
        cin>>job[i].first>>job[i].second;
    }
    sort(job.begin(),job.end());
    priority_queue<int>q;
    int i=0;
    int ans=0;
    rep(j,m+1){
        while(i<n&&j>=job[i].first){
            q.push(job[i].second);
            i++;
            if(i>n-1)break;
        }
        if(q.size()!=0){
            ans+=q.top();
            q.pop();
        }
        
    }
    cout<<ans<<endl;
    return 0;
}