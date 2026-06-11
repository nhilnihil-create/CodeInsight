#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main(void){
    int d, t, s;
    cin >> d >> t >> s;
    cout << ((s * t >= d) ? "Yes" : "No");
    return 0;
}