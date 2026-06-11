#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
using ll = long long;

int main(){
    string str;
    cin >> str;
    map<string, int> days;
    days["SUN"] = 7;
    days["MON"] = 6;
    days["TUE"] = 5;
    days["WED"] = 4;
    days["THU"] = 3;
    days["FRI"] = 2;
    days["SAT"] = 1;
    cout << days[str] << endl;
    return 0;
}
