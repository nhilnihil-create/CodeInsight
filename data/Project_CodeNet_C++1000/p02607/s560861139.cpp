#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n],sq=0;
    for (int i=1;i<=n;i++)
    {
        cin >>a[i];
        if (a[i]%2==1&&i%2==1)
            sq++;
    }
    cout << sq;
    return 0;
}
