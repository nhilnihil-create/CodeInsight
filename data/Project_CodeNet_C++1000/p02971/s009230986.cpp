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
vector<int> A(200050);

//processing
vector<int> B(200050);


//dpTable
int dp[100050];

int main(){
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> A.at(i);
        B.at(i) = A.at(i);
    }
    sort(B.begin(),B.end());
    reverse(B.begin(),B.end());
    ll A1 = B.at(0),A2 = B.at(1);
    for (int i = 0; i < N; i++){
        if (A.at(i) == A1){
            cout << A2 << endl;
        }
        else {
            cout << A1 << endl;
        }
    }
    return 0;
}