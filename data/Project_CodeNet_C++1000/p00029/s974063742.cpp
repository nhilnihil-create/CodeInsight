#include <iostream>
#include <string>
#include <map>

using namespace std;

typedef pair<string, int> elem;

int main()
{
    map<string, int> cnt;
    map<string, int> len;

    string word;
    while (cin >> word) {
        if (cnt.count(word)) {
            cnt.at(word)++;
        } else {
            cnt.insert(elem(word, 1));
            len.insert(elem(word, word.size()));
        }
    }

    pair<string, int> mode("", 0);
    for (auto it = cnt.begin(); it != cnt.end(); it++) {
        if (it->second > mode.second) {
            mode = *it;
        }
    }

    pair<string, int> max_len("", 0);
    for (auto it = len.begin(); it != len.end(); it++) {
        if (it->second > max_len.second) {
            max_len = *it;
        }
    }

    cout << mode.first << " " << max_len.first << endl;

    return 0;
}