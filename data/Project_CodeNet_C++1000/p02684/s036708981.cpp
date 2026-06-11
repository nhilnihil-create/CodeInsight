#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main(){
    long long n,k,x,loopcount=0;
    cin>>n>>k;
    vector<int> a(n),color(n,0),b(n);
    rep(i,n) {
        cin>>x;
        a[i]=--x;
    }
    x=0;
    while(1){
        //cout<<x<<" "<<color[x]<<endl;
        if(color[x]==1){
            break;
        }
        if(loopcount==k){
            cout<<x+1;
            return 0;
        }
        b[x]=loopcount;
        loopcount++;
        color[x]=1;
        x=a[x];
    }
    //cout<<"\n"<<loopcount<<" "<<b[x]<<" "<<x<<endl;
    k=(k-b[x])%(loopcount-b[x]);
    //cout<<k<<endl;
    for(int i=0;i<k;i++){
        x=a[x];
    }
    cout<<x+1;
    }
