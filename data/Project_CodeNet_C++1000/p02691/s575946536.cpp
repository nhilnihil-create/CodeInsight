#include <iostream>
using namespace std;
typedef long long ll;
ll n,a,b[200001],c[200001],ans;
int main(void){
    cin>>n;
    for(ll i=1LL;i<=n;i++){
        cin>>a;
        if(1<=i-a)b[i-a]++;
        if(i+a<=n)c[i+a]++;
    }
    for(int i=1;i<=n;i++){
        ans+=b[i]*c[i];
    }
    cout<<ans<<endl;
}
