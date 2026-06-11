#include <iostream>
#include<deque>
using namespace std;

int main()
{

    char a[3];
    cin >> a[0]>>a[1]>>a[2];
    for (int i = 0; i < 3; i++)
    {
        if(a[i]=='7'){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}