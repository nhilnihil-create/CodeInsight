#include<bits/stdc++.h>
using namespace std;
int main() {
    string s, t;
    cin>>s>>t;
    int sLen = s.size();
    int tLen = t.size();
    int ans = INT_MAX;
    for(int i=0;i<sLen; i++) {
        if(i+tLen <= sLen) {
            string temps = s.substr(i, tLen);
            int tempAns = 0;
            for(int j=0;j<temps.size();j++) {
                if(temps[j] != t[j]) tempAns++;
            }
            ans = min(ans, tempAns);
        } else {
            break;
        }
    }
    cout<<ans<<endl;

}

