#include <bits/stdc++.h>
using namespace std;

vector<string> weather = {"Sunny", "Cloudy", "Rainy"};
int main(void) {
    string S;
    int pos;
    cin >> S;

    for(vector<string>::iterator it = weather.begin();it<weather.end();it++) { 
        if(S == *it) {
            pos = (distance(weather.begin(),it) + 1) % weather.size();
            cout << weather[pos] << "\n";
        }
    }

    return 0;
}
