#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string s = "abcdefghijklmnopqrstuvwxyz";
    char a;
    cin >>a;
    rep(i, s.length()-1){
        if(s[i] == a){
            cout << s[i+1] << endl;
            return 0;
        }
    }
    cout << 'a' << endl;
}