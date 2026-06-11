#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;
    int ans=0;

    int n;
    string s;
    cin>>n>>s;

    if(s.length()<3) {
        cout<<0<<endl;
        return 0;
    }

    for(int i=0;i<s.length()-2;i++) {
        string sub=s.substr(i, 3);
        if(sub=="ABC") {
            ans++;
        }
    }

    cout<<ans<<endl;
    return 0;

}


