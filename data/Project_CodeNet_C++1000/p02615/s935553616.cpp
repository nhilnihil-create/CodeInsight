#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <iterator>
#include <stack>
#include <string.h>
#include <cstdlib>
#include <queue>
#include <list>
#include <string>

using namespace std;

int main()
{
    long long N;
    vector<long long> A;
    long long x;
    long long ans = 0;
    
    cin >> N;
    
    for (int i = 0;i < N;i++){
        cin >> x;
        A.push_back(x);
    }
    
    sort(A.begin(),A.end());
    
    if (N == 2){
        ans = A[1];
    }
    else if (N > 2 && N%2 == 0){
        ans += A[N-1];
        for (int i = 0;i < (N-2)/2;i++){
            ans += 2*A[N-2-i];
        }
    }
    else {
        ans += A[N-1];
        for (int i = 0;i < (N-3)/2;i++){
            ans += 2*A[N-2-i];
        }
        ans += A[(N-1)/2];
    }
    
    cout << ans << endl;
}
