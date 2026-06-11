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
    int X;
    cin >> X;
    int next_prime;
    bool frg1 = false;
    bool frg2 = false;
    if(X==2){
        next_prime = 2;
    }
    else{
        for(int i=X;i>=X;i++){
        for(int j=2;j<i;j++){
            if(i%j==0){
                break;
            }
            else if(j==i-1){
                next_prime = i;
                frg1 = true;
                break;
            }
        }
        if(frg1){
            break;
        }
    }
    }
    
    cout << next_prime << endl;
}