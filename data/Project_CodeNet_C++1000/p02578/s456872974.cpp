#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int tall = 0;
    int max = 0;
    long long stool = 0;
    for(int i = 0; i < n; i++) {
        cin >> tall;
        if (max <= tall) {
            max = tall;
        }
        stool += max - tall;
    }

    cout << stool << endl;
}
