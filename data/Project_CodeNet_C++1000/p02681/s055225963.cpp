#include <bits/stdc++.h>

using namespace std;

int main (){

    string a, b;

    cin >> a >> b;

    if(a == b.substr(0,(b.size()-1))){
        cout << "Yes";
    } else{
        cout << "No";
    }



    return 0;   
}