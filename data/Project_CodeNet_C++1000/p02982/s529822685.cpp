#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;
    int x[n][d];
    for (int i=0; i<n; i++) {
        for (int j=0; j<d; j++) cin >> x[i][j];
    }
    float dist; int cnt = 0;
    for (int k=0; k<n; k++) {
        for (int i=k+1; i<n; i++) {
            int sum = 0;
            for (int j=0; j<d; j++) {
                sum += pow(x[k][j] - x[i][j], 2);
            }
            dist = sqrt(sum);
            if (dist == (int)dist) cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}