#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
const int M = 51;
vector<string> words;

int main() {

    string s;
    cin >> s;
    int L = s.size();
    int k = 0;
    for (int i = 0; i < L/2; i++)
    {
        if(s[i]!=s[L-i-1])k++;
    }
    cout << k;
}
