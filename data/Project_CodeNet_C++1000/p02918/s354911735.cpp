#include<bits/stdc++.h>
using namespace std;
#define INFTY 1<<20
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long int ll;
const int MOD=1000000007;
int main(){

    int n,k;
    string s;
    cin >>n>>k>>s;
    vector<int> cnt(n,0);
    int g=1;cnt[0]=1;
    for (int i = 1; i < n; i++)
    {
        if(s[i]!=s[i-1])g++;
        else cnt[g]++;
    }
    if(g<=2){
        cout<<n-1<<endl;
    }
    else {
        int ans = min(n-g+2*k,n-1);
        cout<<ans<<endl;;
    }
    return 0;   
}