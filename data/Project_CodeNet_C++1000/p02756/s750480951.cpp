#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    deque<char> dq;
    cin >> s;
    for(auto &u : s)
        dq.push_back(u);
    
    int n, op, type;
    bool is_inv = false;
    char c;
    cin >> n;
    while(n--){
        cin >> op;
        if(op == 1){
            is_inv = !is_inv;
        } else {
            cin >> type >> c;
            if(type == 1){
                if(is_inv == false){
                    dq.push_front(c);
                } else {
                    dq.push_back(c);
                }
            } else {
                if(is_inv == true){
                    dq.push_front(c);
                } else {
                    dq.push_back(c);
                }
                
            }
        }
    }
    string ans = "";
    if(is_inv == true){
        while(!dq.empty()){
            ans += dq.back();
            dq.pop_back();
        }
    } else {
        while(!dq.empty()){
            ans += dq.front();
            dq.pop_front();
        }
    }
    cout << ans << "\n";
    return 0;
}