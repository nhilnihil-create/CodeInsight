#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int num;
    string str;

    cin >> num >> str;

    if(num % 2 == 0){
        string tmp1, tmp2;
        tmp1 = str.substr(0, num / 2);
        tmp2 = str.substr(num / 2);
        
        if (tmp1 == tmp2)
            cout << "Yes";
        else cout << "No";
    } else {
        cout << "No";
    }

    //
}
