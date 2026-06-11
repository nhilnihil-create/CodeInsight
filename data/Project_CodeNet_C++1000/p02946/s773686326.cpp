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
    int K,X,N,ans = 1;
    cin >> K >> X;
    int a = max(X - K + 1, -1000000);
    int b = min(X + K - 1, 1000000);
    for(int i = a; i < b+1; i++){
        cout << i;
        if(i == b) cout << " " << endl;
        else cout << " ";
    }
    return 0;
}