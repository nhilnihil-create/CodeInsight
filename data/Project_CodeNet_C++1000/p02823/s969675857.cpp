#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

// 入力
int N;
long long a[110][3]={{0}}; // a[i], b[i], c[i] をそれぞれまとめて a[i][0], a[i][1], a[i][2] にしてしまう

// DP テーブル
long long dp[110][6]={{0}};

int main() {
    long long N,a,b; cin >> N >> a >> b;
    int counter,counter1;
    if((b-a)%2==0){
    cout<<(b-a)/2<<endl;}
    else if(N-b>=a){
    cout<<a+(b-a-1)/2<<endl;}
    else {
    cout<<N-b+(b-a+1)/2<<endl;}
}
    
