#include <iostream>
using namespace std;

#include <sstream>      // std::ostringstream
template <typename T> std::string tostr(const T& t)
{
    std::ostringstream os; os<<t; return os.str();
}

int main() {
    double N;
    int C1, C2;
    cin >> N;
    C1 = (int)( N / 1.08 );
    C2 = C1 + 1;
    string res;
    if ((int)(C1 * 1.08) == N ) {
        res = tostr(C1);
    } else if ((int)(C2 * 1.08) == N ) {
        res = tostr(C2);
    } else {
        res = ":(";
    }

    cout << res << endl;
    return 0;
}

