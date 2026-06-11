#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(string s){
    int n = s.size();
    for(int i = 0; i <= (n-1)/2; i++){
        if(s[i] != s[n-1-i])
            return false;
    }
    return true;
}

int main(){
    string s;
    cin >> s;
    int n = s.size();
    if(check(s.substr(0, n / 2)) &&
        check(s.substr(n / 2 + 1, n / 2)) &&
        check(s)){
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}