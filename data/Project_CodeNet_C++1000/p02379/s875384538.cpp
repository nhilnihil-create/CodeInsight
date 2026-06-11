#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>

using namespace std;

int main() {
    

    double x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << fixed;
    cout << setprecision(6);
    cout << sqrt(pow(x1-x2,2) + pow(y1-y2,2)) << endl;

}
