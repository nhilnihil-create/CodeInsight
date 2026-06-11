#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int main(int argc, char const *argv[]) {
    // #ifndef ONLINE_JUDGE
    //   freopen("input.txt","r",stdin);
    //   freopen("output.txt","w",stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    long long a,v;
    cin>>a>>v;
    long long b,w;
    cin>>b>>w;
    long long t;
    cin>>t;
    long long dist=abs(a-b);
    if((v-w)*t>=dist) cout<<"YES"<<endl; 
    else cout<<"NO"<<endl;
}