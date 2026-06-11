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
    int A,B;
    cin >> A >>B;
 
    for(int i = 1; i <=10000; i++){
        if(int (i*0.08) == A &&  int (i*0.1) == B){
            cout << i << endl;
            return 0;
        }
    }
    cout <<"-1" << endl;
    
 
}