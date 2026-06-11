#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define all(a) (a).begin(), (a).end()


int main(){
    string s;
    cin >> s;
    bool good = true;
    int n = s.size();
    for(int i = 0; i < n; i++){
        if(i % 2){
            if(s[i] == 'R') good = false;
        }else{
            if(s[i] == 'L') good = false;
        }
    }
    if(good) puts("Yes");
    else puts("No");
}
