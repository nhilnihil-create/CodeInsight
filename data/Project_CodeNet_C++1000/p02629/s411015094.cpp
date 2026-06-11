#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    string ans= "";
    
    while(n){
        ans += (char)('a'+ ((n-1)%26));
        if(n%26 != 0)n /= 26;
        else{
            n/=26;
            n--;
        }
    }

    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}