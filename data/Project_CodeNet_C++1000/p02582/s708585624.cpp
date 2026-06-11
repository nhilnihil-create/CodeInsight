#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int rainy = 0, maxx = 0;
    string days;
    cin >> days;

    for (int i = 0; i < days.size(); i ++) {
        if (days[i] == 'R')
            rainy ++;

        if (rainy > maxx)
            maxx = rainy;
        if (days[i] == 'S')
            rainy = 0;
    }

    cout << maxx;

    return 0;
}