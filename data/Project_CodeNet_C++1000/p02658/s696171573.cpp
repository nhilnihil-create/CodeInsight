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
    long long ans = 1;
    vector<long long> A(N);
    bool frg = true;
    for(int i=0;i<N;i++){
        cin >> A[i];
        if(A[i]==0){
            ans = 0;
            frg = false;
            break;
        }  
    }
    if(frg){
        for(int i=0;i<N;i++){
            long long limit = 1e18;
            if(A[i] > (limit / ans)){
                ans = -1;
                break;
            }
            ans = ans * A[i]; 
            
        }
    }
    
    cout << ans << endl;
}