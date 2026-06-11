#include <iostream>
#include <string>
using namespace std;

int main() {
    string S , T ;
    cin >> S >> T ; // S and T are strings of lengths between 1 and 100 (inclusive) consisting of lowercase English letters
    string str[2] = { T , S} ;
    for(int i = 0 ; i <= 1 ; i++){
        cout << str[i] ; } 
	return 0;
}