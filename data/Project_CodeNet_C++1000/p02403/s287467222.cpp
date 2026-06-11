#include <iostream>
using namespace std;
int main() {
cin.tie(0);
ios::sync_with_stdio(false);
int H, W;
while (cin >> H >> W && (H > 0 || W > 0)) {
for (int i = 0; i < H; i++) {
 for (int j = 0; j < W; j++) cout << "#";
 cout << "\n";
}
cout << "\n";
}
}