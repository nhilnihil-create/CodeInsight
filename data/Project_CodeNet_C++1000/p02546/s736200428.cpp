#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define fio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define mod 1000000007
bool compare(int a, int b) {
    return a > b;
}
int main() {
    fio;
    string s;
    cin >> s;
    int x = s.length();
    if (s[x - 1] == 's') {
        s.append("es");
        cout << s << endl;
    }
    else {
        s.append("s");
        cout << s << endl;
    }
    return 0;
}