#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N;
    string s;
    cin >> N >> s;
       
    if (s.substr(0, N/2) == s.substr(N/2)) cout << "Yes" << endl;
    else cout << "No" << endl;
}
