
#include <iostream>
#include <iomanip>
#include <set>
#include <string>
using namespace std;

void Main() {
    // input
    u_int64_t N;
    cin >> N;

    set<string> S;

    for (u_int64_t i = 0; i < N; i++) {
        string str;
        cin >> str;
        S.insert(str);
    }

    // translate


    // output
    cout << S.size() << endl;

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
