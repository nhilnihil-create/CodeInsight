#include<iostream>
using namespace std;
int main()
{
    int h, n;
    cin >> h >> n;
    int a, s = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        s = s + a;
        if(s >= h)
        {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}