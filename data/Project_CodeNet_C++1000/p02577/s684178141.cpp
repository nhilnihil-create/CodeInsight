#include <iostream>
#include <string>
#include <vector>
#include <cmath>
 
using namespace std;
    
int main()
{
    int sum=0;
    int c;
    while((c = getchar()) != EOF){
        if('0' <= c && c <= '9'){
            sum += c-'0';
        }
    }
    cout << (sum%9 ? "No" : "Yes") << endl;
    
    return 0;
}