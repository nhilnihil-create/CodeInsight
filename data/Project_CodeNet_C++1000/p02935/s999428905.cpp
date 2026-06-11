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
    vector<double> v(N);
    for(int i=0;i<N;i++){
        cin >> v[i] ;
    }
    sort(v.begin(),v.end());
    for(int i=1;i<N;i++){
        v[i]= (v[i-1]+v[i])/2 ;
    }
    cout << v[N-1] << endl;
}