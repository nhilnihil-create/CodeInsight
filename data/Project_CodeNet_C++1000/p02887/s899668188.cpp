#include <iostream>
using namespace std;
typedef long long ll;

int main () {
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll ans=1;
    for(int i=1;i<n;i++){
        if (s[i]!=s[i-1])
           ans+=1;
    }
    cout<<ans<<endl;
}