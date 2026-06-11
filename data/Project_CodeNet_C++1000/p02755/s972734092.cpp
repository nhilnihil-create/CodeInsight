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
typedef long long ll;
int main() {
    int A,B;
    cin >> A >> B;
    double min_X,max_X;
    min_X = max(A/0.08, B/0.1);
    max_X = min((A+1)/0.08,(B+1)/0.1);
    for(int i=0;i<=1000;i++){
        if((min_X  <= i)&&(i < max_X)){
            cout << i<< endl;
            break;
        }
        else if(i==1000){
            cout << -1 <<endl;
        }
    }
}