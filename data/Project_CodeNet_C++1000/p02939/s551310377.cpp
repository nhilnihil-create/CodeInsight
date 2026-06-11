#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main(){
    int ans = 0;   
    string s; cin >> s;
    string pre;

    for(;;){
        if(s.size() < 1){ break; }
        string tmp;
        string cur = {s[s.size()-1]};
        if(pre == cur){
            if(cur.size() == 1){
                if(s.size() < 2){
                    break;
                }
                tmp = s.substr(s.size()-2);
                s.erase(s.size()-2);
            }else{
                tmp = s.substr(s.size()-1);
                s.erase(s.size()-1);
            }
        }else{
            tmp = s.substr(s.size()-1);
            s.erase(s.size()-1);
        }
        pre = tmp;
        ans++;
    }
    cout << ans << endl;
}