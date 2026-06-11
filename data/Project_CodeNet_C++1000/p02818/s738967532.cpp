#include <bits/stdc++.h>
 
using namespace std;

#define repr(i,a,b) for (int i=a; i<b; i++)
#define rep(i,n) for (int i=0; i<  n; i++)
 
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
 
const long long INF = 1LL << 60;
#define PI 3.14159265359 
bool dp[100100];

template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}

int main(){
    long long A,B,K;
    cin >> A >> B >> K;

    if( A <= K ){
        K -= A;
        B = max((long long) 0,B-K);
        cout << 0 <<" " << B <<endl; 
    }
    else{
        A -= K;
        cout << A << " " << B << endl;
    }


}
