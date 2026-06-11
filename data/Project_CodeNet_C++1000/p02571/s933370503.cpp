#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s, t;
    cin >> s >> t;
    int length = s.length();
    int l = t.length();
    int ans=0;
    int mini = 10000;
    for (int i = 0; i <= length-l; ++i){
        for (int j = 0; j < l; ++j){
            if(s[j+i] != t[j]){
                ++ans;
            }
        }
        mini = min(ans, mini);
        ans = 0;
    }
    
    cout << mini << endl;
    return 0;
}