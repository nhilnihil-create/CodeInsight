#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <math.h>
#include <algorithm>
#define ll long long
#define add push_back
 
using namespace std; 


int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t;  t = 1; //cin >> t;
    while(t--){
        char ch; cin >> ch;
        if(ch >= 'a' && ch <= 'z')
            cout << "a" << endl;
        else    
            cout << "A" << endl;
    }
    return 0;
}