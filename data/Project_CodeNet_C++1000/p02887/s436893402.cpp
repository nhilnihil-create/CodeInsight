#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
const int N = 2e7+5;
ll a[N];
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans = 1;
    for(int i=1;i<n;i++){
        if(s[i]!=s[i-1])ans++;
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
