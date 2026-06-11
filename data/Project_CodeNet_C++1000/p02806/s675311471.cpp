#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793
 
   
int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    VI t(n);
    string x;
    rep(i,n)cin >> s.at(i) >> t.at(i);
    cin >> x;
    int m=mm;
    ll ans=0;
    rep(i,n){
        if(x==s.at(i))m=i;
        if(i>m)ans+=t.at(i);
    }
    cout << ans << endl;
} 
    