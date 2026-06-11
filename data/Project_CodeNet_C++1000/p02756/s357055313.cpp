#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    string s;
    cin >> s;
    int q;
    cin >> q;
    deque<char> d;
    rep(i,s.size()) d.push_back(s[i]);
    int flag = 0; //0は通常、1は反対
    rep(i,q){
        int t;
        cin >> t;
        if(t == 1) flag ^= 1;
        else{
            int f;
            cin >> f;
            char c;
            cin >> c;
            if(flag == 0){
                if(f == 1) d.push_front(c);
                if(f == 2) d.push_back(c);
            }
            if(flag == 1){
                if(f == 1) d.push_back(c);
                if(f == 2) d.push_front(c);
            }
        }
    }
    if(flag == 0){
        while(!d.empty()){
            cout << d.front();
            d.pop_front();
        }
    }
    if(flag == 1){
        while(!d.empty()){
            cout << d.back();
            d.pop_back();
        }
    }
}