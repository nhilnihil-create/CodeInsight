#include <iostream>

using namespace std;
const int N = 110;
int a[N],b[N];
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n ; i++)
    {
        cin >> a[i] >> b[i];
    }
    for(int i = 1; i <= n - 2; i++)
    {
        if(a[i] == b[i] && a[i+1] == b[i+1] && a[i+2] == b[i+2])
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
