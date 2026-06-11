#include <iostream>
#include<algorithm>
#include<vector>
#define rep(i,n) for(int i = 0; i < (n); i++)

using namespace std;



int main() {
    int n;cin>>n;
    vector<int>w(n);
    rep(i,n)cin>>w[i];
    int ans=99999;
    for (int i = 0; i < n-1; i++)
    {
        int s1=0, s2=0;
        for(int j = 0; j < i+1; j++)s1+=w[j];
        for(int j = i+1; j < n; j++)s2+=w[j];
        ans = min(ans,abs(s1-s2));
    }
    cout<<ans<<endl;

    return 0;
}