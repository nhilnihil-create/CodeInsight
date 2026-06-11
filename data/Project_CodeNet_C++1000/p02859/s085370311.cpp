#include<iostream>
using namespace std;
int main()
{
    int x;
    cin >> x;
    if(x>=1 && x<=100)
    {
        int result = x*x;
        cout << result << endl;
    }
    return 0;
}
