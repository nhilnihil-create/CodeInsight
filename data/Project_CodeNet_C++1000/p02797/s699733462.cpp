#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    int n,k,s;
    cin>>n>>k>>s;

    if(n==k){
        rep(i,n) cout<<s<<" ";
        cout<<endl;
    }
    else if(s==1){
        rep(i,k) cout<<s<<" ";
        rep(i,n-k) cout<<s+1<<" ";
        cout<<endl;
    }
    else{
        rep(i,k) cout<<s<<" ";
        rep(i,n-k) cout<<s-1<<" ";
        cout<<endl;
    }

}