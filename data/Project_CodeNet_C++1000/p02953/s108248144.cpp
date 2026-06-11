#include <bits/stdc++.h>
 
using namespace std;
 
#define repr(i,a,b) for (int i=a; i<b; i++)
#define rep(i,n) for (int i=0; i<  n; i++)
 
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
 
const long long INF = 1LL << 60;
#define PI 3.14159265359 
 
template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}
 
int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}
 
long long lcm (int a, int b){
    return  (long long) a*b /gcd(a,b);
}


int main(){
    int N;
    cin >> N;

    vector<int>H(N);
    rep(i,N)cin >> H[i] ;

    reverse(H.begin(),H.end());

    rep(i,N-1){
        int sa = H[i+1] -H[i];
        if(sa <= 0 )continue;
        else if (sa == 1)H[i+1] -= 1;
        else{
             cout << "No" << endl;
             return 0;
        }
    }
    cout << "Yes" << endl;

}