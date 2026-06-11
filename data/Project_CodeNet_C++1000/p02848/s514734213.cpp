#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n;
    cin >> s;

    for(int i=0; i<s.size(); i++){
        int d = int(s[i] - 'A' + n)%26 + 'A';
        printf("%c", d);
    }

    cout << endl;
    return 0;
}