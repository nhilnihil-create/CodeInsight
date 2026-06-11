#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;



int main(){
    ll n,k;cin>>n>>k;
    if((n-1)*(n-2)/2<k)cout<<-1<<endl;
    else{
        cout<<(n-1)*n/2-k<<endl;
        for(int i=1;i<=n-1;i++){
            for(int j=i+1;j<=n;j++){
                if(j!=n&&k){
                    k--;
                }
                else{
                    cout<<i<<" "<<j<<endl;
                }
            }
        }
    }
}

    







