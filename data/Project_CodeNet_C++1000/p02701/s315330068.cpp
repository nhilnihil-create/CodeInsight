#include<iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

int gcd(int p, int q) {
    if (p % q == 0)return q;
    return gcd(q, p % q);
}

int main()
{
    int n;
    int count = 1;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    
    sort(s.begin(), s.end());

    for (int i = 0; i < n-1; i++) {
        if (s[i] != s[i + 1]) {
            count++;
        }
    }

    cout <<  count;
    
    return 0;
}

