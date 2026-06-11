#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
const int N = 2e7+5;
ll a[N];
void solve(){
    int n;
    cin>>n;
    ll sum = 0;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            sum+=a[i]*a[j];
        }
    }
    cout<<sum<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
//    cin>>t;
    while(t--)solve();
    return 0;
}
