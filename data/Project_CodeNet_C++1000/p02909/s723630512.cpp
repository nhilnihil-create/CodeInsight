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
    vector<string> scs{"Sunny","Cloudy","Rainy"};
    string s; cin >> s;
    auto itr = find(scs.begin(),scs.end(),s);
    int i =itr-scs.begin();
    int out ;
    if(i==2) out = 0;
    else out = i+1;
    cout << scs[out] << endl;
    return 0;
}