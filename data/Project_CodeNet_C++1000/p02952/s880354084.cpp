#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <functional>
#include <map>
#include <set>
#include <tuple>
#include <cassert>
#include <bitset>
using namespace std;
int main(){
    int N,i,a;
    cin >> N;
    a = 0;
    for(i = 1;i <= N;i++){
        string S = to_string(i);
        if (S.size() % 2 == 1) a++;
    }
    cout << a << endl;
}