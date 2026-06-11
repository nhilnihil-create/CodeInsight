#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;

int main(){
    string s;
    cin >> s;
    bool isbad = false;
    rep(i,3){
        if(s.at(i) == s.at(i + 1)) isbad = true;
    }
    cout << (isbad ? "Bad" : "Good") << endl;
}
