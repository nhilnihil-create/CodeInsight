#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<=(n);++i)
#define Rep(i,s,n) for(int i=(s);i<=(n);++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const double Pi = acos(-1);
const ll mod=1e9+7;

int main(){
    int n;
    cin >>n;
    string s;
    cin >>s;
    int ans=0;
    for(int i=0;i<n-2;i++){
        if(s[i]=='A' && s[i+1]=='B' && s[i+2]=='C'){
            ans++;
        }
    }
    cout << ans <<endl;
    return 0;
}