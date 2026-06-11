#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    int cnt = 0;
    cin >> n;
    for (int a = 1; a <= n; a++){
        for (int b = 1; b <= (n/a); b++){
            if (n-a*b > 0) {
                cnt++;
            }
        }
    }
    cout << cnt;
}
