#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <random>
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
#include <bitset>
#include <sstream>

typedef  long long ll;
#define mop 1000000007
using namespace std;

bool judge(string s){
    if(s.length()%2 != 0) return false;
    for (ll i=0;i<s.length();i++){
        if(i%2 == 0){
            if(s[i] != 'h') return false;
        }else{
            if(s[i] != 'i') return false;
        }
    }
    return true;
}

int main() {
    
    string s;
    cin >> s;
    cout << (judge(s)?"Yes":"No") << endl;
}