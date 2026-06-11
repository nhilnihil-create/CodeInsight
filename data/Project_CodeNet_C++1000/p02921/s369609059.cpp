#include <iostream>
#include <string>
using namespace std;

int main() {
    string S, T ;
    cin >> S >> T ; //S and T are strings of length 3 each , S and T consist of 'S' , 'C', and 'R'.
    int X = 0 ;
    if ( S[0] == T[0]) X++ ;
    if ( S[1] == T[1]) X++ ;
    if ( S[2] == T[2]) X++ ;
    cout << X <<endl ;
	return 0;
}