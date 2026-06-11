#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    int sum = 0;
    int cnt = 0;
    cin >> n;
    for (int i=0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (cnt < 3) {
            if (a == b){
                cnt += 1;
            } else {
                cnt = 0;
            }
        }
    }
    if (cnt >= 3) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}
