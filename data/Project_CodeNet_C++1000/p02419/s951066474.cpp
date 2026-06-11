#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

int main()
{
    string w, t;
    int count = 0;

    cin >> w;
    transform(w.begin(), w.end(), w.begin(), ::tolower);

    while (cin >> t) {
        transform(t.begin(), t.end(), t.begin(), ::tolower);

        if (t.compare(w) == 0) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}