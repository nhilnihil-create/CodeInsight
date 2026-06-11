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
int N;
vector<int> d(100050);

//processing



//dpTable
//int dp[100050];

int main(){
    cin >> N;
    rep(i,N){
        cin >> d.at(i);
    }
    sort(d.begin(),d.end());
    reverse(d.begin(),d.end());
    cout << d.at(N / 2 - 1) - d.at(N / 2) << endl;
    return 0;
}