#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <functional>
#include <map>
#include <set>
#include <tuple>
#include <cassert>
#include <bitset>

using namespace std;
int main(){
    int N,i,K,A;
    cin >> N;
    int D[N];
    for(i = 0;i < N;i++) cin >> D[i];
    sort(D,D + N);
    A = 0;
    for(K = D[(N / 2) - 1] + 1;K <= D[N / 2];K++) A++;
    cout << A << endl;
}