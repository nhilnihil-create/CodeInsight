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
    vector<int> p(N);
    vector<int> q(N);
    for(int i=0;i<N;i++){
        cin >> p[i] ;
    }
    for(int i=0;i<N;i++){
        cin >> q[i] ;
    }
    //
    vector<int> Num(N);
    for(int i=0;i<N;i++){
        Num[i]= i+1;
    }
    //
    map<vector<int>,int>permutation;
    int cnt =0;
    while(next_permutation(Num.begin(), Num.end())){
        cnt++;
        permutation[Num] = cnt;   // map[vector] = int;
    }
    cout << abs(permutation[p] - permutation[q]) << endl;
}