#include <iostream>
using namespace std;
int main()
{
    string t;
    cin >> t;
    for(size_t i = 0; i < t.size(); i++) {
        printf("%c", (t[i] == '?' ? 'D' : t[i]));
    }
    cout << endl;
    return 0;
}