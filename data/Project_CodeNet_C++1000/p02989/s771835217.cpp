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
    //
    vector<int> d(N+1);
    d[0]=0;
    for(int i=1;i<=N;i++){
        cin >> d[i] ;
    }
    sort(d.begin(),d.end());
    //
    int cnt;
    //
    int K_max = d[(N/2)+1];
    int K_min = d[(N/2)] + 1;
    //
    if(d[N/2]==d[(N/2)+1]){
        cnt = 0;
    }
    else{
        cnt = K_max - K_min + 1;
    }
    cout << cnt << endl;
}