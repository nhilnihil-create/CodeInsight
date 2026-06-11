#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<string>s(n);
    vector<int>t(n);
    for(int i=0;i<n;i++)cin >> s[i] >> t[i];
    string x;
    cin >> x;
    int ans = 0;
    bool chk = false;
    for(int i=0;i<n;i++){
        if(chk){
            ans += t[i];
        }else if(x==s[i]){
            chk = true;
        }
    }
    cout << ans<<endl;
    
}