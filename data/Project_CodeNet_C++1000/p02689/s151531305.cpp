#include <bits//stdc++.h>
#define rep(i,n) for(int i = 0;i < n;i++)
using namespace std;
typedef long long ll;

int main(){
    int n,m;
    cin>>n>>m;
    int h[n];
    rep(i,n)cin>>h[i];
    map<int,bool>mp;
    rep(i,n)mp[i]=true;
    
    rep(i,m){
        int j,k;
        cin>>j>>k;
        if(h[j-1]>h[k-1])mp[k-1]=false;
        else if(h[j-1]==h[k-1]){
            mp[j-1]=false;
            mp[k-1]=false;
        }
        else mp[j-1]=false;
    }

    int sum=0;
    rep(i,n)if(mp[i])sum++;
    cout<<sum<<endl;

    return 0;
}