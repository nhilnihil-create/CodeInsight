#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
const int N = 2e7+5;
ll a[N];
ll b[N];
void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[a[i]]++;
    }
    sort(a,a+n);
    int ans = 0;
    for(int i=00;i<n;i++){
        for(int j=i+1;j<n;j++){
            int x = a[i]+a[j];
            int cnt=  1;
            if(a[i]==a[j])cnt=2;
            int y = (upper_bound(a,a+n,x-1)-a);
            if(y>j)ans+=y-j-1;
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
//    cin>>t;
    while(t--)solve();
    return 0;
}
