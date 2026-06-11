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
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
const long long INF = 1LL << 60;
typedef long long ll;
int main() {
    int N,M;
    cin >> N >> M;
    vector<int> AC(N+1,0);
    vector<int> WA(N+1,0);
    for(int i=0;i<M;i++){
        int p;
        string S;
        cin >> p;
        if(AC[p]==1){
            cin >> S;
        }
        else if(AC[p]==0){
            cin >> S;
            if(S=="AC"){
                AC[p]=1;
            }
            else if(S=="WA"){
                WA[p]++;
            }
        }
    }
    int accnt=0;
    int penalty=0;
    for(int i=1;i<=N;i++){
        accnt+= AC[i];
        if(AC[i]>0){
            penalty+= WA[i];
        }
    }
    cout << accnt << " " << penalty << endl;
    
}