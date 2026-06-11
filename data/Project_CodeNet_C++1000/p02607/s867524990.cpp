#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n;
int a[105];
int ans;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i%2==0&&a[i]%2==1){
            ans++;
        }
    }
    cout<<ans<<endl;
    
}
