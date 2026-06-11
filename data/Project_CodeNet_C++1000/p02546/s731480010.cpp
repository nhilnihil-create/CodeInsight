#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
/*def*/
    string s;
/*input*/
    cin >> s;

/*main*/
    if (s.back()=='s') {
        s+="es";
    }
    else{
        s+="s";
    }
/*output*/
    cout << s << endl;
}
