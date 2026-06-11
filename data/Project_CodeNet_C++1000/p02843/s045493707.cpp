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
    int x;
    cin >> x;
    bool frg=true;
    for(int i=100;i<=105;i++){ // x>1 よりx%i==0となるiが複数存在することはありえない
        if(x%i==0){
            frg = false;
            cout << 1 << endl;
        }
    }
    bool frg1 = true;
    if(frg){
        int num = x /100;
        if(x%100<=5*num){
            cout << 1 << endl;
            frg1 = false;
        }
        else if(frg1){
            cout << 0 <<endl;
        }
    }
    
}