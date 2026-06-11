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
    cin>> N;
    int A[N+1], B[N];
    rep(i,N+1)cin >> A[i];
    rep(i,N)cin >> B[i];

    long long ans = 0;
    rep(i,N){
        if(B[i] >= A[i]){
            B[i] = B[i]-A[i];
            if(B[i] >= A[i+1]){
                ans += A[i]+ A[i+1];
                A[i+1] = 0;
            }else{
                A[i+1]-= B[i];
                ans += A[i]+B[i];

            }
        }else{
            ans += B[i];
        }
    }

    cout << ans << endl;


}