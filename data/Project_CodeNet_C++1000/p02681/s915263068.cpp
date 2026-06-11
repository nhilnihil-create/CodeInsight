#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

#define si(x) scanf("%d", &x)

int main(){
    bool ok = false;
    string s, t;

    cin >> s >> t;

    if (s.length() == t.length() - 1 ){
        if(s == t.substr(0, s.length())){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }else
    {
        cout << "No\n";
    }
    

    return 0;
}