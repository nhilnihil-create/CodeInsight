#include <iostream>

using namespace std;

int main()
{
    int n, m;
    std::cin >> n >> m;
    for(int i = 1; 2 * i < m + 2; ++i){
        cout << i << " " << m + 2 - i << "\n";
    }
    for(int i = m + 2; 2 * i < 3 * m + 3; ++i){
        cout << i << " " << 3 * m + 3 - i << "\n";
    }
}