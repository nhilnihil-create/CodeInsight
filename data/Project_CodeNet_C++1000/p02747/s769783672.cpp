#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL);
    string s;
    cin >> s;
    int n = s.length();
    bool ok = true;
    for(int i=0;i<n;i+=2) {
        if(s[i] != 'h' || s[i+1] != 'i') {
            ok = false;
            break;
        }
    }
    cout << ((ok) ? "Yes" : "No") << endl;
    return 0;
}
