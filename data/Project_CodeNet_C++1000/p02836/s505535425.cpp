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
    string t = s;
    reverse(all(s));
    int n = s.size();
    int count = 0;
    for(int i = 0; i < n; i++){
        if(s[i] != t[i]) count++;
    }
    cout << count / 2 << endl;
}
