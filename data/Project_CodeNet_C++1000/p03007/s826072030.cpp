#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
struct Process{
    int x;
    int y;
};
signed main(){
    int n;cin>>n;
    vector<int> a(n);
    rep(i,n){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int sum=0;
    vector<Process> p(n-1);
    rep(i,n){
        sum+=max(a[i],-a[i]);
    }  
    if(a[0]>0){
        sum-=2*a[0];
    }
    if(a[n-1]<0){
        sum+=2*a[n-1];
    }
    cout<<sum<<endl;
    rep1(i,n-2){
        if(a[i]>0){
            p[i-1].x=a[0];
            p[i-1].y=a[i];
            a[0]-=a[i];
        }
        else{
            p[i-1].x=a[n-1];
            p[i-1].y=a[i];
            a[n-1]-=a[i];
        }
    }
    p[n-2].x=a[n-1];
    p[n-2].y=a[0];
    rep(i,n-1){
        if(a[n-1]<0){
            p[i].x=a[0];
            p[i].y=a[i+1];
            a[0]-=a[i+1];
        }
        cout<<p[i].x<<" "<<p[i].y;
        cout<<endl;
    }
    return 0;
}