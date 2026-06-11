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
    int max=0;
    int second_max=0;
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    int max_i;
    int second_max_i;
    for(int i=0;i<N;i++){
        if(max < A[i]){
            max = A[i];
            max_i = i;
        }
    }
    for(int i=0;i<N;i++){
        if((i!=max_i)&&(second_max<A[i])){
            second_max = A[i];
            second_max_i = i;
        }
    }
    for(int i=0;i<N;i++){
        if(i!=max_i){
            cout << max << endl;
        }
        else{
            cout << second_max << endl;
        }
    }
}