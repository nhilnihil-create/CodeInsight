#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <utility>
#include <tuple>
#include <cstdio>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>
#define _GLIBCXX_DEBUG
using namespace std;
const long long INF = 1LL << 60;
int main() {
    int N;
    cin >> N;
    int X;
    double Y = N / 1.08;
    for(int i=1;i<=50000;i++){
        X = i;
        if(( (X-(1/1.08)) < Y)&&( Y <= X ) ) {
            cout << X << endl;
            break;
        }
        else if(i==50000){
            cout <<":(" << endl;
        }
    }
}