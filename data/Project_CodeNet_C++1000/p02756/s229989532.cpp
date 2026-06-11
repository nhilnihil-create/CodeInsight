#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    string s;
    cin >> s;
    deque<char> deq;
    int n = s.size();
    for(int i = 0; i < n; i++){
        deq.push_back(s[i]);
    }
    int q;
    cin >> q;
    bool rev = false;
    for(int i = 0; i < q; i++){
        int t;
        cin >> t;
        if(t == 1 && !rev) rev = true;
        else if(t == 1) rev = false;
        else {
            int f;
            cin >> f;
            char c;
            cin >> c;
            if(f == 2 && !rev) deq.push_back(c);
            else if(f == 2) deq.push_front(c);
            else if(f == 1 && rev) deq.push_back(c);
            else deq.push_front(c);
        }
    }
    while(!deq.empty()){
        if(!rev){
            cout << deq.front();
            deq.pop_front();
        } else {
            cout << deq.back();
            deq.pop_back();
        } 
    }
    cout << endl;
    return 0;
}