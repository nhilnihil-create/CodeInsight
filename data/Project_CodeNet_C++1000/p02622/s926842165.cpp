#include <iostream>

using namespace std;

int main()
{

    string s, k;    cin >> s >> k;
    int num = 0;
    for (int i = 0; i < s.size(); i++){
        if (s[i] != k[i]){
            num++;
        }
    }

    cout << num << endl;

    return 0;
}
