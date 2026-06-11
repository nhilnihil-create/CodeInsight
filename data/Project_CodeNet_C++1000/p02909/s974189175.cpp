#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string S;
    cin >> S;

    string ans;
    if (S == "Sunny")
    {
        ans = "Cloudy";
    }else if(S == "Cloudy")
    {
        ans = "Rainy";
    }else if (S == "Rainy")
    {
        ans = "Sunny";
    }
    
    cout << ans << endl;
    
    return 0;
}