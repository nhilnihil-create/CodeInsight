#include <iostream>

using namespace std;

int main()
{
    string s , t;
    cin >> s >> t;
    if (t == s + t[s.size()]){
        cout << "Yes";
    }else{
        cout << "No";
    }
    return 0;
}
