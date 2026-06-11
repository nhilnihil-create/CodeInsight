#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str, target;
    cin >> str >> target;
    
    str += str;
    string::size_type index = str.find(target);
    cout << (index == string::npos ? "No" : "Yes") << endl;
    
    return 0;
}