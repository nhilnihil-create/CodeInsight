#include <iostream>
#include <string>
using namespace std;

int main()
{
    string S;
    cin >> S;

    int out;
    if(S == "SUN") {
        out = 7;
    } else if(S == "MON") {
        out = 6;
    } else if(S == "TUE") {
        out = 5;
    } else if(S == "WED") {
        out = 4;
    } else if(S == "THU") {
        out = 3;
    } else if(S == "FRI") {
        out = 2;
    } else if(S == "SAT") {
        out = 1;
    }

    cout << out << endl;
    return 0;
}