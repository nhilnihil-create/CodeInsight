#include<bits/stdc++.h>

using namespace std;

int n;
int k;
int x;
int y;
string s;
int main()
{
    cin >> n >> k >> s;
    for(int i = 1; i < n; i ++){
        x += (s[i - 1] == s[i]);
        y += (s[i - 1] != s[i]);
    }
    cout << x + min(y, k * 2) << "\n";
}
