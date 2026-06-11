#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    char a;
    string ans;
    cin >> a;
    
    if (isupper(a)) ans = "A";
    else ans = "a";
   
    cout << ans << endl;
}