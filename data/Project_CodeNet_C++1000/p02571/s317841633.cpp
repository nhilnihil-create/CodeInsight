#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define PI 3.1415926535897932384626433
#define ceil1(a,b)   (a+(b-1))/b
#define all(v)  v.begin(),v.end()
#define gen(arr,n,nxt)  generate(arr,arr+n,nxt)
#define base ios_base::sync_with_stdio(false);cin.tie(0);
#define open freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
using namespace std;
const int mo=1e9+7;
int nxt(){int x;cin>>x;return x;}
int mod(int n,int m){int ans=n%m;if(ans<0)ans+=m;return ans;}
int32_t main(){
    base
    string s,t;
    cin>>s>>t;
    int Min=1e18;
    for(int i=0;i<=s.size()-t.size();i++){
        int cnt=0;
        for(int j=0;j<t.size();j++){
            cnt+=s[i+j]!=t[j];
        }
        Min=min(Min,cnt);
    }
    cout<<Min;
    return 0;
}
