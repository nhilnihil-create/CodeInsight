
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
    string S;
    cin >> S;
    if (S.back() == 's') {
        cout << S + "es" << endl;
    }
    else {
        cout << S + 's' << endl;
    }
        
    
    return 0;
}