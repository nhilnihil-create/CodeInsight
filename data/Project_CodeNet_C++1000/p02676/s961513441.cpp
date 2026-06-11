#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int k;
    string str;
    cin >> k >> str;
    int size = str.length();
    int i;
    if (size > k){
        for (i = 0; i < k ;i++){
            cout << str[i];
        }
        cout << "..."<< endl;
    }
    else {cout << str << endl;}
}