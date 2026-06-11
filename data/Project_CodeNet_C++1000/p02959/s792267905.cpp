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
    int N;
    cin >> N;
    //
    vector<int> A(N+1);
    for(int i=0;i<N+1;i++){
        cin >> A[i];
    }
    //
    vector<int> B(N);
    for(int j=0;j<N;j++){
        cin >> B[j];
    }
    //
    ll total=0;
    for(int i=0;i<N+1;i++){
        if(i==0){
            if(A[i]>=B[i]){
                total += B[i];
                B[0]=0;
            }
            else{
                total += A[i];
                B[0]-=A[0];
            }
        }
        else{
            if(A[i] <= B[i-1]){
                total+= A[i];
            }
            else{
                if(A[i] > B[i] + B[i-1]){
                    total += B[i] + B[i-1];
                    B[i-1]=0;
                    B[i]=0;
                }
                else{
                    total += A[i];
                    B[i] = B[i] - (A[i] - B[i-1]);
                }
            }
        }
    }
    cout << total << endl;
}