#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
    int N;
    cin>>N;
    int p[N];
    int cnt=0;
    rep(i,N){
        cin>>p[i];
        if(i+1!=p[i]){
            cnt++;
        }
    }
    if(cnt==0||cnt==2){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    
    
}
