#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int n;
    string s;
    cin >> n >> s;

    if (n < 1 || n > 100){
        cout << "No" << endl;
        return 0;
    } 

    if ((n % 2) == 1){
        cout << "No" << endl;
        return 0;
    }
   
    if (n != s.size()){
        cout << "No" << endl;
        return 0;
    } 

    for (int i = 0; i < n; i++) {
        char c = s[i];
        //cout << "c = " << c << endl;
        if (isupper(c)){
            cout << "No" << endl;
            return 0;
        }
    }

    string harf = s.substr(n / 2);
    //cout << "harf = " + harf << endl;

    if (s == harf + harf){
        cout << "Yes" << endl;
        return 0;
    }else{
        cout << "No" << endl;
        return 0;
    }
}