#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

int main() {
    string s; cin >>s;
    int ret = 0;
    if (s.size()==1) {ret = 1;}
    else if (s.size() == 2 && s[0] == s[1]) { ret = 1;}
    else if (s.size() == 2 && s[0] != s[1]) { ret = 2;}
    else {
        string bef = "";
        while (true) {
            if (s.size()==3) {
                if (bef==s.substr(0,1)) {ret+=2;break;}; // bef is 1 char: ab-c
                if (bef!=s.substr(0,1) && s[0]!=s[1] && s[1]!=s[2]) {ret+=3;break;} // a-b-c or a-b-a
                ret+=2; break;
            }
            if (s.size()==2) {
                if (bef!=s.substr(0,1) && s[0]!=s[1]) {ret+=2;break;}
                else {ret+=1;break;}
            }

            int i = 1;
            while ( s.substr(0,i) == bef ) i++;
            bef = s.substr(0,i);
            s = s.substr(i,s.size()-i);
            ++ret;
        }
    }
    cout << ret << endl;
    return 0;
}