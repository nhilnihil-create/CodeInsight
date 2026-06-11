#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <ctype.h>
#include <algorithm>
#include <cmath>
#include <vector>

#define REP(i, n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()
#define square(x) (x) * (x)

const int INF = 1e9;

using namespace std;

int main() {
    int count[26] = {0};
    string word;
    while(getline(cin, word) != NULL) {
        REP(i, word.size()){
            char c = word[i];
            if((c-'a') >= 0 && (c-'z') <= 0)
                c -= 0x20;
            c -= 'A';
            if (0 <= c && c <= 25)
            count[c]++;
        }
    }

    REP(i, 26){
        char c = i + 'a';
        cout << c << " : " << count[i] << endl;
    }

    return 0;
}