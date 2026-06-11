#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    long long n;
    string s;
    cin >> n >> s;

    long long ans = 0;
    for(char c1 = '0'; c1 <= '9'; c1++){
        if(s.find(c1) == string::npos) continue;
        string s1 = s.substr(s.find(c1)+1);

        for(char c2 = '0'; c2 <= '9'; c2++){
            if(s1.find(c2) == string::npos) continue;
            string s2 = s1.substr(s1.find(c2)+1);

            for(char c3 = '0'; c3 <= '9'; c3++){
                if(s2.find(c3) != string::npos) ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}