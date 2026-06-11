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
    int max_cnt=0;
    int cnt=0;
    int H;
    cin >> H;  // i=0
    for(int i=1;i<N;i++){
        int h;
        cin >> h;
        if(h <= H){
            cnt++;
        }
        else{
            cnt = 0;
        }
        if(max_cnt < cnt){
            max_cnt = cnt;
        }
        H = h;
    }
    cout << max_cnt << endl;
}