#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n; cin >> n;
    string s; cin >> s;

    for(int i=0; i<s.length(); i++){
        s[i] += n;
        if(s[i] > 90) s[i] -= 26;
    }

    cout << s << endl;

    // char c = 'A';
    // for(int i=0; i<=64; i++){
        
    //     cout << i << ":" << (char)(c + i) << " "<< c + i << endl;
    // }    
}
