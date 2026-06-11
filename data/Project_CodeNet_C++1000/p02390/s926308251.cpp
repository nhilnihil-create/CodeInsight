#include<iostream>

using namespace std;

int main() {
    int S;
    cin >> S ;
    int h = S/3600 ;
    S = S%3600;
    int m = S/60;
    S = S%60;
    int s = S;
    cout << h << ":" << m  << ":" << s  << endl;
  
     return 0;
}  
