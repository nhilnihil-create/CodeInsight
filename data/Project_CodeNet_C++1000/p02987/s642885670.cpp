#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(a) (a).begin(), (a).end()


int main(){
    string s;
    cin >> s;
    map<char,int> count;
    for(char x : s){
        count[x]++;
    }
    bool flag = true;
    for(auto p : count){
        if(p.second != 2){
            flag = false;
        }
    }
    if(flag) puts("Yes");
    else puts("No");
}
