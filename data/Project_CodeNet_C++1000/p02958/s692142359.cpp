#include<iostream>
using namespace std;
int main()
{
    int n, p[100], k = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> p[i];
        if(p[i] != i + 1)
            k++;
    }
    if(k <= 2)
    {
        cout << "YES";
        return 0;
    }
    else
        cout << "NO";
    return 0;
}