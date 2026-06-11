#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    string word;
    string longest = "";
    pair<int, string> frequent = make_pair(0, "");
    map<string, int> dictionary;

    while (cin >> word)
    {
        dictionary[word] += 1;

        if (dictionary[word] > frequent.first)
        {
            frequent = make_pair(dictionary[word], word);
        }
        if (word.size() > longest.size())
        {
            longest = word;
        }
    }
    cout << frequent.second << " " << longest << endl;
}
