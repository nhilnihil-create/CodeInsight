#include <bits/stdc++.h>
using namespace std;
string s,t;

int main(){
    cin >> s >> t;
    int mn = 1e9;
    for(int i=0; i<=s.length()-t.length(); i++){
        int curr = 0;
        for(int j=0; j<t.length(); j++){
            if(s[j+i]!=t[j]){
                curr++;
            }
        }
        mn = min(mn,curr);
    }
    cout << mn << endl;
}
