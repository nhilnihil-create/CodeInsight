#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    long long int A, V, B, W, T; cin >> A >> V >> B >> W >> T;
    bool t = false;
    int i = 0;
    if (A >= B) {
        while (i <= T) {
            if (B >= A) {
                t = true; break;
            }
            else {
                A -= V, B -= W, i++;
            }
        }
    }
    else {
        while (i <= T) {
            if (A >= B) {
                t = true; break;
            }
            else {
                A += V, B += W, i++;
            }
        }
    }
    if (t) printf("%s\n", "YES");
    else printf("%s\n", "NO");
}
