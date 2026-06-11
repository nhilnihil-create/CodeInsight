/* 
 * Project: AtCoder Beginners Contest 159 B - String Palindrome
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/06/15
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[100];

bool is_palindrome(char *s) {
    int n = strlen(s);
    for (int i=0;i<n;i++) {
        if (s[i] != s[n-i-1])
            return false;
    }
    return true;
}

void solve() {
   
    int n = strlen(s);
    if (!is_palindrome(s)) {
        printf("No\n");
        return;
    }
    char s_h[(n-1)/2+1];
    char s_f[(n-1)/2+1];
    strncpy(s_h, s, (n-1)/2);
    strncpy(s_f, s+(n-1)/2+1, (n-1)/2+1);
    s_h[(n-1)/2] = '\0';
    s_f[(n-1)/2] = '\0';
    if (is_palindrome(s_h) && is_palindrome(s_f)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}

int main() {

    scanf("%s", s);

    solve();

}