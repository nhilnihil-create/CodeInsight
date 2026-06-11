#include <bits/stdc++.h>
 
using namespace std;
#define repr(i,a,b) for (int i=a; i<b; i++)
#define rep(i,n) for (int i=0; i<  n; i++)
 
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
 
const long long INF = 1LL << 60;
#define PI 3.14159265359 
bool dp[100100];
 
 
int main () {
    int N; string S;
    cin >> N >> S;
    long long r =0, g =0, b = 0;
    for(auto c : S){
        if(c == 'R') ++r;
        else if(c == 'G') ++g;
        else ++b;
    }

    long long all = r*g*b;
    long long sub =0;
    for(int i = 0; i<N; ++i){
        for(int j =i+1; j<N; ++j){
            if(S[i]== S[j])continue;
            int k  =j*2-i;
            if(k>=N || S[k] == S[i]|| S[k]== S[j])continue;
            ++sub;
        }
    }
    cout << all-sub << endl;





}