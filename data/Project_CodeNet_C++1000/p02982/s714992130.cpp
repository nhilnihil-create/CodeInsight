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
    int N,D;
    cin >>  N >> D;
    map<int,vector<int>> data;
    for(int i=0;i<N;i++){
        vector<int> X(D);
        for(int j=0;j<D;j++){
            cin >> X[j];
        }
        data[i]=X;
    }
    int cnt=0;
    int num = N*(N-1)/2;
    vector<int> dist(num);
    int cn=-1;
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            int distance=0;
            for(int k=0;k<D;k++){
                distance = distance + (data[i][k] - data[j][k])*(data[i][k] - data[j][k]);
            }
            cn++;
            dist[cn]=distance;
        }
    }
    for(int i=0;i<num;i++){
        for(int j=0;j<160;j++){
            if(dist[i] == j*j){
                cnt++;
            }
        }
    }
    cout << cnt<< endl;
}