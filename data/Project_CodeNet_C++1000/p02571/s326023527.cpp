#include<bits/stdc++.h>

using namespace std;
#define ll  long long
#define ld  long double
#define endl '\n'
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ll MOD = (ll) 1e9 + 7;
const double PI = 3.141592653589793238463;
const int MAXN = 1000005;

int main() {
    FAST
    string s,t;
    cin>>s>>t;
    int ans=INT_MAX;
    for(int i=0;i<s.size()-t.size()+1;i++){
        int c=0;
        for(int j=0,k=i;j<t.size();k++,j++){
            if(s[k]!=t[j])
                c++;
        }
        ans=min(ans,c);
    }
    cout<<ans<<endl;


    return 0;
}
