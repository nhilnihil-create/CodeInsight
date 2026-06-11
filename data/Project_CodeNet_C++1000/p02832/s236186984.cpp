#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n,a[200005];
int k=1;
int ans;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==k){
            k++;
        }else{
            ans++;
        }
    }
    if(k==1){
        cout<<-1<<endl;
        return 0;
    }
    cout<<ans<<endl;

}
