#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;


int main(){
    int a,b;
    cin>>a>>b;
    double ans;
    if(floor(a/0.08*0.1)==b)
        ans=a/0.08;
    else if(floor(b/0.1*0.08)==a)
        ans=b/0.1;
    else
        ans=-1;
    
    cout<<ceil(ans)<<endl;
}