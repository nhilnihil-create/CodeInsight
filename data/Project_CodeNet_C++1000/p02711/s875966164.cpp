#include <iostream>

using namespace std;

int main()
{
    int n , a;
    cin >> n;
    for (int i = 0 ; i < 3 ; i++){
        a = n % 10;
        if (a == 7){
            cout << "Yes";
            return 0;
        }
        n /= 10;
    }
    cout << "No";
    return 0;
}
