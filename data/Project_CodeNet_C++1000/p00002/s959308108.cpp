#include <iostream>
using namespace std;
int main()
{
    int a, b;
    while(cin >> a >> b){
        int num = a + b;
        int count = 0;
        while(num){
            count++;
            num /= 10;
        }
        cout << count << endl;
    }
    return(0);
}