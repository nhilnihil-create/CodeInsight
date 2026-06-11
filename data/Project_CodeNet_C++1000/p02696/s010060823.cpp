#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mxN=1e5+1;
vector<string>op(mxN);

vector<char>ans;

signed main(){
    int a,b,n;
    cin>>a>>b>>n;
    int tk=min(b,n);
    if(tk==b)
        tk-=1;
    int ans=a*tk;
    ans/=b;
    cout<<ans<<endl;
}