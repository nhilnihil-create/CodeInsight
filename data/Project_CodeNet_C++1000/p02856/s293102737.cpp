#include <iostream>
using namespace std;
typedef long long ll;
ll n,a,b,ans=-1,tot;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        ans+=b;
        tot+=(a*b);
    }
    ans+=(tot-1)/9;
    cout<<ans<<endl;
}
