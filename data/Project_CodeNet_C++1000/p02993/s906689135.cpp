#include <iostream>
#include <numeric>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <iterator>
#include <stack>
#include <string.h>
#include <cstdlib>
#include <queue>
#include <list>
#include <string>
#include <iterator>
#include <iomanip>
#define rep(i,n) for(int i = 0; i < (n); i++) 
using namespace std;

int main() {
    long long int n;
    string str;
    bool flag = true;
    cin >> str;
    rep(i,str.size()-1) {
        if(str[i] == str[i+1]){
            flag = false;
        }
    }
    if (flag) {
        cout << "Good" << endl;
    } else {
        cout << "Bad" << endl;
    }
    
    return 0;
}