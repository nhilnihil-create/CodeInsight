#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll=long long;
#define chmax(x, y) { x = max(x, y); }
#define chmin(x, y) { x = min(x, y); }

int main(){
    int n,i=1;
    cin>>n;

    while(true){
        if(n-1000*i<=0){
            cout<<-(n-1000*i)<<endl;
            return 0;
        }
        i++;
    }
}