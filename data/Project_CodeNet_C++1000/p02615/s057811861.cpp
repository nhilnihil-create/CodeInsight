#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define INF 999999999
#define rep(i,n) for(int i=0;i<n;i++)
const int MOD = 1000000007;
ll cnt =0,ans=0;

int main(){
    int n;  cin >> n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a.at(i);
    }
    sort(a.begin(),a.end());

    for(int i=1;i<n;i++){
        ans+=a.at(n-i/2);
    }

    cout << ans << endl;


}