#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,t;
    cin>>s>>t;
    int n=s.size();
    int m=t.size();
    int mn=INT_MAX;
    for(int i=0;i+m<=n;i++){
        string k=s.substr(i,m);
        int cnt=0;
        for(int j=0;j<m;j++){
            if(k[j]!=t[j])cnt++;
        }
        mn=min(mn,cnt);
    }
    cout<<mn<<endl;
}
