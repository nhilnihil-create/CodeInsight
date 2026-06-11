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
    int cost=0;
    int minmum_cost;
    vector<int> X(N);
    for(int i=0;i<N;i++){
        cin >> X[i];
    }
    for(int i=1;i<=100;i++){
        cost = 0;
        for(int j=0;j<N;j++){
            cost = cost + (X[j]-i)*(X[j]-i);
        }
        if(i==1){
            minmum_cost = cost;
        }
        else{
            if(cost < minmum_cost){
                minmum_cost = cost;
            }
        }
    }
    cout << minmum_cost << endl;
}