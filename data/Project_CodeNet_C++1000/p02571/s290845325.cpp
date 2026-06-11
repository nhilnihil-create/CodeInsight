#include <bits/stdc++.h>
using namespace std;;
 
int main(){
    string s,t;
    cin >> s >> t;
    int ssize,tsize;
    ssize = s.length();
    tsize = t.length();
    int ans = tsize;
    for (int i = 0; i <= ssize-tsize; i++){
        int count = 0;
        for (int j = 0; j < tsize; j++){
            if (s[i+j] != t[j]){
                count++;
            }
        }
        ans = min(ans,count);
    }
    cout << ans << endl;
}