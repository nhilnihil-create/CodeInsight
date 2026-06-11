#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,i;
    string s;
    cin >> n >> s;

    for(i=0; i<s.size(); i++){

//        s[i] = s[i] + n;
//        cout << (int)s[i] + n;


        if((int)s[i] + n <= 90){
            s[i] = s[i] + n;
            cout << s[i];
        }else{
            s[i] = s[i] - (26 - n);
            cout << s[i];
       }
    }

    cout << endl;
}