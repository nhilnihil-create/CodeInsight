#include <iostream>
#define ll long long
#define the_flash ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

int main() 
{
    the_flash;
    
    int n, count = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (num != i + 1)
            count++;
    }

    if (count > 2)
        cout << "NO" << "\n";
    else 
        cout << "YES" << "\n";
    return 0;
}