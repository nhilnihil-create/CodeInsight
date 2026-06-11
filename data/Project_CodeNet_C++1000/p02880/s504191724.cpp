#include<iostream>
using namespace std;
int main()
{
    int i, n, j, A[100] = {0};
    cin >> n;
    for(i=1;i<=9;i++)
    {
        for(j=1;j<=9;j++)
        A[i*j]=1;
    }
    if(A[n] == 1)
    cout << "Yes";
    else
    {
        cout << "No";
    }
    return 0;
}