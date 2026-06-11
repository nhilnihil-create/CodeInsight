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

int x[10],y[10];

double dis (int i, int j){
    int dx = abs(x[i]-x[j]);
    int dy = abs(y[i]-y[j]);

    return  sqrt(dx*dx + dy*dy);
 }
 //あとで取る
 
 
int main(){
    int N;
    cin >> N;

    vector<int> a(N);
    rep(i,N)cin >> a[i];

    int sum=0;
    int j = 1;
    for(int i = 0; i<N;i++){
        while(a[i] == j){
            j++;
        }
    }
    if(j == 1) cout << -1 << endl;
    else cout << N-(j-1) << endl;


 
}