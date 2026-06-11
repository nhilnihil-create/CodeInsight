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
    int K,N;
    cin >> K >> N;
    vector<int> A(N) ;
    int longest;
    for(int i=0;i<N;i++){
        cin>> A[i] ;
    }
    for(int i=1;i<=N;i++){
        if(i==1){
            longest = abs(A[i] - A[i-1]);
        } 
        else if((i>1)&&(i<N)){
            int distance = abs(A[i]- A[i-1]);
            if(distance > longest){
                longest = distance;
            }
        }
        else if(i==N){
            int distance = abs(A[0]+ abs(K - A[i-1]));
            if(distance > longest){
                longest = distance;
            }
        }
    }
    int ans = K - longest;
    cout << ans << endl;
}