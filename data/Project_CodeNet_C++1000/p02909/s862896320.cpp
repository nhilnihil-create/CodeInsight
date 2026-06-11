#include <bits/stdc++.h>
using namespace std;

int main(void){
 
    string s;
    cin >> s;
    
    if(s[0] == 'S'){
        cout << "Cloudy" <<endl;
    }
    else if(s[0] == 'C'){
        cout << "Rainy" <<endl;
    }
    else{
        cout << "Sunny" <<endl;
    }
}