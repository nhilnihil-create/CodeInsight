#include <bits/stdc++.h>

using namespace std;

int main(){
        int a,b,c;
        cin >> a >> b >> c;

        if (a >= b + c){
                cout << "0" << endl;
        }
        else if (a < b + c){
                cout << c - (a - b) << endl;
        }
        return 0;
}