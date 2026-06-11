#include<bits/stdc++.h> 
using namespace std;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;
    string ans;
    ans = "";
    string alp="abcdefghijklmnopqrstuvwxyz";

    long long n;
    cin>>n;
    
    while(n>0) {
        n--;
        ans+=alp[(n%26)];
        n/=26;
    }

    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;

}


