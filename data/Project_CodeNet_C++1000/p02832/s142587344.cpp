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
    //
    vector<int> a(N);
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    //
    int num=1;
    for(int j=0;j<N;j++){
        if(a[j]==num){
            num++;
        }
    }
    int ans;
    ans = N - num + 1;
    if(ans==N){
        ans =  -1;
    }
    cout << ans << endl;
}