#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <cmath>  //sqrt 
#include <iomanip> //setprecision
using namespace std;

int main(){
    vector<string> scs{"SUN","MON","TUE","WED","THU","FRI","SAT"};
    string s; cin >> s;
    auto itr = find(scs.begin(),scs.end(),s);
    int i =itr-scs.begin();
    cout << 7-i << endl;
    return 0;
}