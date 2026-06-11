#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdint>

using i16 = std::int16_t;
using i32 = std::int32_t;
using i64 = std::int64_t;
template<class T>
using Vector = std::vector<T>;
using String = std::string;
using std::to_string;
using std::cin;
using std::cout;
using std::getline;
using std::stoi;
using std::endl;

void program();

int main()
{
    std::ios::sync_with_stdio(false);
    program();
}

void program() {
    auto line = String();
    getline(cin, line);

    int sum = 0;
    for (i32 i = 0; i < (i32)line.size(); ++i) {
        sum += (i32)(line[i] - '0');
        sum %= 9;
    }
    if (sum == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}
