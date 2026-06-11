#include<bits/stdc++.h>
using namespace std;

int main(){
    string s,t; cin >> s >> t;

    int ans = pow(10,9);
    for(int i=0; i<s.size(); i++){
        int cnt = 0;
        if(i+t.size() <= s.size()){
            for(int j=0; j<t.size(); j++){
                if(s[i+j] != t[j]) cnt++;
            }
            ans = min(ans, cnt);
        }else{
            break;
        }
    }

    cout << ans << endl;

}