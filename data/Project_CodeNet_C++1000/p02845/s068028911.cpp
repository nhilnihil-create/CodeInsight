#include <iostream>
using namespace std;
typedef long long ll;
ll n,s[100001],a,ans=1,MOD=1e9+7;
int main(void){
    cin>>n;
    s[0]=3;
    for(int i=0;i<n;i++){
        cin>>a;
        ans*=s[a];
        ans%=MOD;
        s[a]--;
        s[a+1]++;
    }
    cout<<ans<<endl;
}
