#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<numeric>

using namespace std;

int main(){
    map<string, int> map;
    map["SUN"] = 0;
    map["MON"] = 1;
    map["TUE"] = 2;
    map["WED"] = 3;
    map["THU"] = 4;
    map["FRI"] = 5;
    map["SAT"] = 6;

    string s;
    cin >> s;
    cout << 7 - map[s] << endl;
}