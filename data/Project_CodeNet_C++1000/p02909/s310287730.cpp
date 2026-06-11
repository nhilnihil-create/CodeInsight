#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    string S;
    cin >> S;

    map<string, string> w;
    w["Sunny"] = "Cloudy";
    w["Cloudy"] = "Rainy";
    w["Rainy"] = "Sunny";

    cout << w[S] << endl;

}