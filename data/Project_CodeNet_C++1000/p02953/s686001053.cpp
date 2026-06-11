#include <bits/stdc++.h>
using namespace std ;
typedef long long ll;

int main(){
    int n;cin>>n;
    int h[n+1],d[n+1];
    h[0]=0;d[0]=0;
    for(int i=1;i<=n;i++){
        cin>>h[i];d[i]=0;
    }
    d[n]=h[n];
    for(int i=n;i>=1;i--){
        if(h[i-1]<=d[i])d[i-1]=h[i-1];
        else if(h[i-1]==d[i]+1) d[i-1]=d[i];
        else if(h[i-1]>d[i]+1){
            cout << "No"<<endl;
            return 0;
        }
    }
    cout <<"Yes"<<endl;
}