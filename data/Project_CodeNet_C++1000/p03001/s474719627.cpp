#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int w, h, x, y;
    cin >> w >> h >> x >> y;

    printf("%f %d\n", double(w)*double(h)/2, x*2 == w && y*2 == h);
    return 0;
}
