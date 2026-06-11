#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <set>
#include <map>
#include <stack>
#include <deque>
#include <iterator>
#include <iomanip>
#include <queue>
using namespace std;


int main(){
    long long n, k, mx = 0;
    string s;
    cin >> n >> k >> s;
    for(int i = 0; i < n - 1; ++i){
        if(s[i] == s[i + 1]) mx++;
    }
    cout << min(mx + k * 2, n - 1);
}