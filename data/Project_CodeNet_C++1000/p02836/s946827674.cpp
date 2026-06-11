#include<bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define moduloP 1e9 + 7

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin>>s;
    
    int n=(int)s.size(), count=0;
    
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n-1-i])
            count++;
    }
    cout<<count;
    return 0;
}
