#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s; cin >> s;
    int n = s.size();
    int ans = 1,uku = 1;
    for(int i=1;i<n;){
        if(uku==1){
            if(s[i]!=s[i-1]){
                ans++;
                i++;
            }else{
                if(i!=n-1) ans++;
                i+=2;
                uku = 2;
            }
        }else{
            ans++;
            i++;
            uku = 1;
        }
    }
    cout << ans << endl;
    return 0;
}