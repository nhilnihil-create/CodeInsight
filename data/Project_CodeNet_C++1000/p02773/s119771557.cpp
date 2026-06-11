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
    int N;
    cin >> N;
    vector<string> vec(N);
    for (int i=0;i<N;i++){
        cin >> vec.at(i);
    }
    sort(vec.begin(), vec.end());
    string S = vec.at(0);
    int c = 1;
    int x = 0;
    
    for (int i = 0; i < N-1; i++) {
        if (vec.at(i+1) == S){
        c ++;
        }
        else {
        S = vec.at(i+1);
        c = 1;
        }
        x = max(c, x);
    }
    int y = 0;
    S = vec.at(0);
    
    for (int i = 0; i < N; i++) {
        if (vec.at(i) == S)
        y ++;
        else {
        S = vec.at(i);
        y = 1;
        }
        if (y == x){
        cout << vec.at(i) << endl;
        }
    }
}
// 模範解答そのまま
// 全く分からなかった。