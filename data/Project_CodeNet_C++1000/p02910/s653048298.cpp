#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //I don't care about anybody, and fuck ratings! I'll go to google!
    string s; cin>>s;
    int n = s.size();
    bool ok = 1;
    for(int i = 0; i<n; i++){
        if((i%2==1 && s[i]=='R') || (i%2==0 && s[i]=='L')) ok = 0; 
    }
    cout<<(ok?"Yes\n":"No\n");
    return 0; 
}
