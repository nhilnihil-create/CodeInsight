#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<fstream>

#define MOD (1000000007)

using namespace std;

typedef long long int Int;

constexpr Int TEN(int n) { return n == 0 ? 1 : 10 * TEN(n-1); }

const int max_n = 2000+10;
Int dp[max_n][max_n];
int N;

int main(void) {
    cin>>N;

    vector<pair<Int,int>> A;
    for(int i = 0;i < N;i++) {
        Int a;
        cin>>a;
        A.push_back({a,i});
    }

    sort(A.begin(),A.end(),greater<pair<Int,int>>());

    for(int i = 0;i < N;i++) {
        for(int j = 0;j < i+1;j++) {
            Int a = A[i].first;
            int p = A[i].second;
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+(p-j)*a);
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]+((N-(i-j)-1)-p)*a);
        }
    }

    Int sum = 0;
    for(int i = 0;i <= N;i++) 
        sum = max(dp[N][i],sum);

    cout<<sum<<endl;

    return 0;
}
