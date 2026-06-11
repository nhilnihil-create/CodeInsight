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
    int N,K,Q;
    cin >> N >> K >> Q;
    //
    vector<int> point(N,(K-Q));
    for(int i=0;i<Q;i++){
        int A;
        cin >> A;
        point[A-1]+=1;
    }
    for(int i=0;i<N;i++){
        if(point[i]>0){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
}