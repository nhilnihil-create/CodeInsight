#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using P = pair<int, int>;

#define loop(i, n) for(int i = 0;i < n;i++)
#define IINF 2e9
#define MOD 1e9+7

int main(void){

    string s;
    cin >> s;

    for(int i = 0; i < s.size();i++){
        if(s[i] == '?') cout << 'D';
        else cout << s[i];
    }
    cout << endl;

    return 0;
}