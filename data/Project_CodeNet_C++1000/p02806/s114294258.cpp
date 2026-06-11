#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=1;i<=n;i++)
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define pb push_back
using namespace std;


int main(){
    int n,sum=0;
    cin>>n;
    vector<string> s(n);
    vector<int> t(n);
    rep(i,n) cin>>s[i]>>t[i];
    string x;
    cin>>x;
    rep(i,n){
        if(x==s[i]){
            for(int j=i+1;j<n;j++) sum += t[j];
        }
    }
    cout<<sum<<endl;
    return 0;
}