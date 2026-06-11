#include <bits/stdc++.h>
using namespace std;
#define N 9
void reads(string& x) {char kk[N]; scanf("%s", kk); x = kk;}

string s;

int main () {
    reads(s);
    if (s[2] == s[3] && s[4] == s[5]) {
        printf("%s\n", "Yes");
    } else {
        printf("%s\n", "No");
    }
    return 0;
}