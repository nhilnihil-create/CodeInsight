#include<iostream>
using namespace std;

int main()
{
    int n, i, x, y, c, flag = 0;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> x >> y;
        if(x == y)
        {
            c+=1;
            if(c == 3)
            flag = 1;
        }
        else
        c = 0;
    }
    if(flag == 1)
    cout << "Yes";
    else
    cout << "No";
    return 0;
}