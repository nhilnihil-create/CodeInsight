#include <iostream>
#include <vector>
using namespace std;
int main(void){
    // Your code here!
    int k, a, b;
    string s;
    cin >> k >> a >> b;
    
    for(int i = 0; i < 1000; ++i)
    {
        if( k * i >= a && k * i <= b)
        {
            s = "OK";
            break;
        }
        else
        {
            s ="NG";
        }
    }
    
    cout << s << endl;
}
