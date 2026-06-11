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
#include <limits>
#include <iomanip>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
const long long INF = 1LL << 60;
typedef long long ll;
int main() {
    int N;
    cin >> N;
    vector<vector<int>> data(N, vector<int>(2));
    for(int i=0;i<N;i++){
        cin >> data[i][0] >> data[i][1]; // x -  y
    }
    //
    double total=0;
    double cnt=0;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            double num = (data[i][0] - data[j][0])*(data[i][0] - data[j][0]) + (data[i][1] - data[j][1])*(data[i][1] - data[j][1]);
            double distance = sqrt(num);
            total += distance;
            cnt++;
        }
    }
    double average = total /cnt ;
    cout << fixed << setprecision(10) << average *(N-1)<< endl;
}