#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,N) for(int i = 0; i < (N); i++)
#define erep(i,N) for(int i = N; i >= 0; i--)
#define PI 3.1415926535

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true;} return false;}

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true;} return false;}

char upper(char c){
    if('a' <= c && c <= 'z'){
        c = c - ('a' - 'A');
    }
    return c;
}

char lower(char c){
    if('A' <= c && c <= 'Z'){
        c = c + ('a' - 'A');
    }
    return c;
}

const ll INF = 1000000000000000000;

//input
int N,M;
int A[105];


//processing
int hoge,ans;


//dpTable
//int dp[100050];

int main(){
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        hoge += A[i];
    }
    hoge = (hoge + 4 * M - 1) / (4 * M);
    for (int i = 0; i < N; i++){
        if (A[i] >= hoge) ans++; 
    }
    cout << (ans >= M ? "Yes" : "No") << endl;
    return 0;
}
