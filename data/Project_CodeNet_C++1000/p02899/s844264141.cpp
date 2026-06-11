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
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i] ;
    }
    vector<int> B(N);
    for(int i=0;i<N;i++){
        B[A[i]-1]=i;
    }
    for(int i=0;i<N;i++){
        if(i<N-1){
            cout << B[i]+1 << " ";
        }
        else{
            cout << B[i] + 1 << endl;
        }
    }
}