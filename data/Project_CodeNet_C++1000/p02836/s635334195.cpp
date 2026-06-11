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

    string s; cin >> s;
    int n = s.size();
    int out = 0;
    for (int i = 0; i <n/2; i++)
    {
        if(s[i]!=s[n-1-i]){
            out++;
        }
    }
    cout << out << endl;
    
    return 0;
}