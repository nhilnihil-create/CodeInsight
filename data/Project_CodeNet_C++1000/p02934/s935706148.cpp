#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define ll long long
using namespace std;

const ll mod = 1e9 + 7;

ll C[2005][2005];
ll dp[100005][13];

int main(){
    float a,N,ans = 0;
    cin >> N;
    for(int i=0; i<N;i++){
        cin >> a;
        ans += 1.0/a;
    }
    cout << 1.0 / ans << endl;
    return 0;
}