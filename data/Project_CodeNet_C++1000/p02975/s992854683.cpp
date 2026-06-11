#define _LIBCPP_DEBUG 0
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef vector<int> vi;
typedef long long ll;



int main(){
    ll N,a[100010];
    cin>>N;
    rep(i,0,N)cin>>a[i];
    sort(a,a+N);
    int ok=0;
    int jud=(a[0]^a[N/3])^a[2*N/3];
    if(a[0]==0&&a[N-1]==0)ok=1;
    else if(N%3==0&&a[0]==0&&a[2*N/3-1]==0&&a[2*N/3]==a[N-1])ok=1;
    else if(N%3==0&&a[0]==a[N/3-1]&&a[N/3]==a[2*N/3-1]&&a[2*N/3]==a[N-1]&&jud==0)ok=1;
    if(ok)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    

    
}




