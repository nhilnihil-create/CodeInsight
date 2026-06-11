#include <iostream>
#include<map>

using namespace std;
#define fin(ans) cout << (ans) << '\n'
int main()
{
    map<string,string> m;
    m["Sunny"] = "Cloudy";
    m["Cloudy"] = "Rainy";
    m["Rainy"] = "Sunny";
    string S;
    cin >> S;
    fin(m[S]);
    return 0;   
}