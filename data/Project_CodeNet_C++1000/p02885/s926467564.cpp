#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
const int N = 2e7+5;
void solve(){
    int a,b; 
    cin>>a>>b; 
    cout<<max(0,a-2*b)<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
//    cin>>t;
    while(t--)solve();
    return 0;
}
