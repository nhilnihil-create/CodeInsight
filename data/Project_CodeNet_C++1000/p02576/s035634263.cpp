#include<iostream>
using namespace std;
int main()
{
    int n, x, t, allt;
    cin >> n >> x >>t;
    if(n%x==0)
        allt= n/x*t;
    else
        allt=(n/x+1)*t;

    cout << allt;
    return 0;
}
