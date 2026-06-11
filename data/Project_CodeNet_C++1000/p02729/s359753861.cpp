
#include <iostream>
#include <iomanip>
using namespace std;

void Main() {
    // input
    int N, M;
    cin >> N >> M;


    // translate
    int ans = 0;
    ans += (N * (N - 1)) / 2;
    ans += (M * (M - 1)) / 2;


    // output
    cout << ans << endl;

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
