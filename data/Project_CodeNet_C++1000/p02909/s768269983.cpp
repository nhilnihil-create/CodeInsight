#include <iostream>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
using ll = long long;

using namespace std;



int main() {
    string s;
    cin >> s;
    string p;
    if(s=="Sunny") p = "Cloudy";
    else if(s=="Cloudy") p = "Rainy";
    else if(s=="Rainy") p = "Sunny";

    cout << p << endl;

    return 0;
}
