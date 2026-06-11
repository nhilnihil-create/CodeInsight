#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
string s;



int main(){

    int n;
    cin>>n;
    int ans=0;
    int b[n-1];
    for(int i=0;i<n-1;i++)
        cin>>b[i];
    ans+=b[n-2]+b[0];
    for(int i=n-2;i>0;i--){
        ans+=min(b[i],b[i-1]);
    }
    cout<<ans;

return 0;
}
