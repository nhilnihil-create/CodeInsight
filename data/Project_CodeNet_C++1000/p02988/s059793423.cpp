#include<iostream>
using namespace std;
int main()
{
    int n,p[100], k = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for(int i = 1; i < n - 1; i++)
    {
        if((p[i] > p[i-1] && p[i] < p[i+1]) || (p[i] < p[i-1] && p[i] > p[i+1]))
            k++;
    }
    cout << k;
}