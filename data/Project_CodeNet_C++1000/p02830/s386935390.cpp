#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <cmath>  //sqrt 
#include <iomanip> //setprecision
using namespace std;

int main(){
    cout << fixed << setprecision(6);
    int n; cin >> n;
    string s,t; cin >> s >> t;
    string out ="";
    for (int i = 0; i < n; i++)
    {
        out += s[i];
        out += t[i];
    }
    cout << out << endl;
    
    return 0;
}