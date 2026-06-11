#include <iostream>

using namespace std;

int main()
{
    string one,two;
    int c=0;
    cin >> one >> two;
    for(int i=0;i<one.length();i++){
        if(one[i]!=two[i]){
            c++;
        }
    }
    cout << c;


    return 0;
}
