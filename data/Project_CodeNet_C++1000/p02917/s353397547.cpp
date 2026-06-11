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
    vector<int> B(N-1);
    for(int i=0;i<N-1;i++){
        cin >> B[i];
    }
    vector<int> A(N);
    for(int i=0;i<N;i++){
        if(i==0){
            A[i]=B[0];
        }
        else if(i==N-1){
            A[i]=B[N-2];
        }
        else{
            A[i]=min(B[i-1],B[i]);
        }
    }
    ll ans=0;
    for(int i=0;i<N;i++){
        ans = ans + A[i];
    }
    cout << ans << endl;
}