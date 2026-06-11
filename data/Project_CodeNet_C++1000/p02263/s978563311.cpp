#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    stack<ll> s1;
    string word;
    while( cin >> word ) {
        if ( (int) word.length() == 1 && !isdigit( word[0] ) ) {
            ll first = s1.top(); s1.pop();
            ll second = s1.top(); s1.pop();

            if ( word == "+" ) s1.push( first + second );
            else if ( word == "-" ) s1.push( second - first );
            else if ( word == "*" ) s1.push( second * first );
        } else {
            s1.push ( atoi(word.c_str()) );
        }
    }

    cout << s1.top() << endl;
    return 0;
}

