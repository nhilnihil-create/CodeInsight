#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int A, B;

    cin >> A >> B;

    int count = 0;

    
    while (true)
    {
        if (count * (A - 1) + 1 >= B)
            break;

        count++;
    }
    
    

    cout << count << endl;
    
}