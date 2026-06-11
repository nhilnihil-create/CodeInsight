#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;



int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int c = 0;
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n / 2; i++){
        c += (s[i] != s[n - 1 - i]);
    }
    cout << c;

    return 0;
}
