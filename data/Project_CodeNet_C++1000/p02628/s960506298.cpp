#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int k;
    int result = 0;
    cin >> n >> k;
    int a[n];
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    for(int i = 0;i < k;i++)
    {

        result = result + a[i];
    }
    cout << result << endl;
    return 0;
}
