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
    int count = 0;
    for(int i = 0; i < str.size()/2; i++){
        if(str.at(i) != str.at(str.size()-1-i)){
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
