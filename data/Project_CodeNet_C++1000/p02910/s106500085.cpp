#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;

    cin >> s;
    int len = s.length();


    for(int i = 0;i < len;i++){

       if(i % 2 == 0){
         if(s.at(i) == 'L'){
           cout << "No";
           return 0;
         }
    }else{
        if(s.at(i) == 'R'){
           cout << "No";
           return 0;
         }
    }
    
    }
    cout << "Yes";
}

   