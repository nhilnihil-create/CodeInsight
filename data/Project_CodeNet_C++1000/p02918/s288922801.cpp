#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n,k;
    string s;
    cin>>n>>k>>s;
    int ans=0;
    int c=0;
    for (int i=1;i<n;i++) {
        if (s[i-1]==s[i])
            ans++;
        else
            c++;
    }
    cout<<ans+min(c,k*2)<<endl;
    return 0;
}