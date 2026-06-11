#include<iostream>
using namespace std;
int main()
{
    int n, t = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        if(i <= 9 || (i >= 100 && i <=999) || (i >= 10000 && i <= 99999))
           t++;
    }
    cout << t;
    return 0;
}