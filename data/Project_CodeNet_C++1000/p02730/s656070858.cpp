#include <string>
#include <algorithm>
#include <iostream>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;

bool kaibun(string s) {
    if(s.length()==1) return true;
    string ss = s;
    reverse(s.begin(),s.end());
    if(s==ss) return true;
    else return false;
}

int main(void) {
    string S; cin >> S;
    string s1 = S.substr(0,S.length()/2);
    string s2 = S.substr(S.length()/2+1,S.length()/2);
    if(kaibun(S) && kaibun(s1) && kaibun(s2)) cout << "Yes" << endl;
    else cout << "No" << endl;
}