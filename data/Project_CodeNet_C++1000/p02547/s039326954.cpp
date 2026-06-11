#include <iostream>                                                
#include <vector>  
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <map>
#define endl "\n"

using ll = long long;
using namespace std;

int main() {
    int N;
    cin >> N;
    string three = "No";
    int count = 0;
    while (N--) {
        pair<int, int>roll;
        cin >> roll.first;
        cin >> roll.second;
        if (roll.first == roll.second) {
            count++;
        }
        else if (roll.first != roll.second) {
            count = 0;
        }
        if (count == 3) {
            three = "Yes";
            break;
        }

    }
    cout << three << endl;
    
    return 0;
}