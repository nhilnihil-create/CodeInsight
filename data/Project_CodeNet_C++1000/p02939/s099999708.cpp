#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
#define pii pair<int, int>
#define ss second
#define ff first 


int main(){
    string s;
    cin >> s;

    int ans=0;
    bool ok=false;
    for(int i=0; i<(int)s.length(); ++i){
        if(ok){
            ans++;
            ok = false;
        }
        else{
            if(s[i] != s[i+1]){
                ans++;
                continue;
            }
            else{
                ans++;
                ++i;
                ok=true;
            }
        }
    }
    cout << ans;
}
