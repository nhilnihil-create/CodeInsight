#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
typedef long long ll;
typedef pair<int,int> pii;

int main(){
    int n,k;
    cin>>n>>k;
    
    if(k>(n-1)*(n-2)/2){
        cout<<-1<<endl;
        return 0;
    }

    ll m = n-1+(n-1)*(n-2)/2-k;
    cout<<m<<endl;

    for(int i=2;i<=n;i++){
        cout<<1<<" "<<i<<endl;
    }
    int cnt =0;

    bool fl = false;
    for(int i=2;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(cnt == (n-1)*(n-2)/2-k){
                fl=true;
            }
            if(fl) break;
            cout<<i<<" "<<j<<endl;
            cnt++;
        }
        if(fl) break;
    }

    return 0;
}