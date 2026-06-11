#include <iostream>
#include <string>

using namespace std;

int main()
{
    string st1, st2;
    int count = 0;

    cin >> st1 >> st2;

    for(auto i = 0; i < st1.size(); i++) {
        if(st1[i] != st2[i]) ++count;
    }

    cout << count << endl;

    return 0;

}