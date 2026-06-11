#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    srand((unsigned)time(NULL));
    string s; cin >> s;

    int n = s.size();
    while(true) {
        int t = rand() % n;
        if(t + 3 <= n) {
            cout << s.substr(t, 3) << endl;
            return 0;
        }
    }
}