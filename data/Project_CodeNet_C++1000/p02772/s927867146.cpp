#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int a[n];
    int ans = 1;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i]%2==0)
        {
            if((a[i]%3==0) || (a[i]%5==0))
            {
            }
            else
            {
                ans = 0;
                break;
            }

        }
    }
    cout << (ans == 1 ? "APPROVED" : "DENIED") << endl;

    return 0;
}
