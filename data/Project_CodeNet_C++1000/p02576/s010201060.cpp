#include <iostream> // cin, cout を利用
using namespace std;
 
#include <iostream> // cin, cout を利用
using namespace std;
 
int main() {
    int N, X, T;
    cin >> N >> X >> T;

    int times = (N + X - 1) / X;
    int ans = T * times;

    cout << ans << endl;

}
