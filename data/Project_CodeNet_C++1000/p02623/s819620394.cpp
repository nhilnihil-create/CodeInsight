#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
const int N = 3e5 + 1;
int n, m, k;
long long int A[N], B[N], cs[N], sum; 
int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    for(int i = 0; i < m; i++){
        cin >> B[i];
        cs[i + 1] = cs[i] + B[i];
    }
    int answer = upper_bound(cs, cs + m + 1, k) - cs - 1;
    for(int i = 0; i < n; i++){
        sum += A[i];
        if(sum > k)break;
        int value = upper_bound(cs, cs + m + 1, k - sum) - cs - 1;
        answer = max(answer, (i + 1) + value);
    }
    cout << answer << endl;
    return 0;
}