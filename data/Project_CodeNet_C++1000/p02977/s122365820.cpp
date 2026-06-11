#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int p = 0;
    int l = n;
    while(l % 2 == 0){
        l /= 2;
        p <<= 1;
        p |= 2;
    }
    if(l == 1){
        cout << "No" << endl;
        return 0;
    }
    l = n;
    cout << "Yes" << endl;
    cout << 2 << " " << n + 1 << endl;
    if(p){
        cout << p << " " << n << endl;
        cout << n - 1 << " " << n + p + 1 << endl;
        cout << n - 2 << " " << n << endl;
        cout << n + p << " " << n * 2 - 2 << endl;
        cout << n * 2 - 2 << " " << n * 2 - 1 << endl;
        cout << n * 2 - 2 << " " << n * 2 << endl;
        l -= 3;
    }
    for(int i = 2; i < l; i += 2){
        cout << 1 << " " << i + 1 << endl;
        cout << 1 << " " << i + n << endl;
        cout << i << " " << i + 1 << endl;
        cout << i + n << " " << i + n + 1 << endl;
    }
}