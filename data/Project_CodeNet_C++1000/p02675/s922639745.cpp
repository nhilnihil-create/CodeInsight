#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int N, a;
    cin >> N;
    
    if(N < 10)
    {
        a = N;
    }
    else if (10 <= N || N < 100)
    {
        a = N % 10;
    }
    else
    {
        a = N % 100;
    }
    
    if(a == 2 || a == 4 || a == 5 || a == 7 || a == 9)
    {
        cout << "hon" << endl;
    }
    else if(a == 0 || a == 1 || a == 6 || a == 8)
    {
        cout << "pon" << endl;
    }
    else
    {
        cout << "bon" << endl;
    }
}
