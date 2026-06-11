/**
 *   @FileName	a.cpp
 *   @Author	kanpurin
 *   @Created	2020.09.13 20:15:54
**/

#include "bits/stdc++.h" 
using namespace std; 
typedef long long ll;

int main() {
    string s; cin >> s;
    if (s[2] == s[3] && s[4] == s[5]) {
        puts("Yes");
    }
    else {
        puts("No");
    }
    return 0;
}