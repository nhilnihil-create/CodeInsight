#include <iostream>
#include <string>
#include<vector>
#include<algorithm>

using namespace std;

int main () {
    int n, l;
    cin >> n >> l;

    vector<int> ata(n);
    vector<int> ataab(n);
    for (int i = 0; i < n; i++)
    {
        ata[i] = l + i;
        ataab[i] = abs(ata[i]);
    }

    int min = 200;
    int minID;
    for (int i = 0; i < n; i++)
    {
        if(ataab[i] < min) {
            min = ataab[i];
            minID = i;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if(i != minID) {
            ans += ata[i];
        }

    }

    cout << ans << "\n";
}