#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<math.h>
#include<map>
using namespace std;
int main() {
    string s;
    cin >> s;
    string hi = "";
    for(int i=0;i<=5;i++){
        hi += "hi";
        if(hi == s){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}