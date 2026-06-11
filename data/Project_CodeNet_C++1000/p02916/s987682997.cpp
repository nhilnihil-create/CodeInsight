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

    int a[N+1],b[N+1],c[N];

    for(int i = 1; i< N+1; i++) cin >> a[i];
    for(int i = 1; i< N+1; i++) cin >> b[i];
    for(int i = 1; i< N; i++) cin >> c[i];

    int sum = 0;
    repr(i,1,N+1){
        sum += b[a[i]];
    }

    repr(i,1,N){
        if(a[i]+1 == a[i+1]){
        sum += c[a[i]];
        }
    }
    cout << sum << endl;

}