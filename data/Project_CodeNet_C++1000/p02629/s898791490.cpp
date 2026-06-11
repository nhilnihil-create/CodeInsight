#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    string word = "";
    int i = 1;
    while (i < 12 && n > 0) {
        long long m = n % (long long)pow(26,i);
        if (m == 0) {
            n = n - pow(26,i);
            word = "z" + word;
        } else {
            int a = m / pow(26,i-1);
            n = n - a*pow(26,i-1);
            if (a != 0) {
                char c = a - 1 + 'a';
                word.insert(0,1,c);
            }
        }   
        i++;
    }
    cout << word;
}
