#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;

const int MAX = 80;

int main(){
    int N;
    int A[MAX];
    long long DP[MAX] = {0};
    long long ans = 0;

    DP[0] = 1000;

    cin >> N;
    for(int i = 0;i < N;i++){
        cin >> A[i];
    }


    for(int i = 1;i < N;i++){
        long long m = 0;

        for(int j = 0;j < i;j++){
            long long n = A[i] * (DP[j] / A[j]) + DP[j] % A[j];
            m = max(n,m);
        }

        DP[i] = max(DP[i - 1],m);
    }

    for(int i = 0;i < N;i++){
        ans = max(ans,DP[i]);
    }

    cout << ans << endl;

    return 0;
}