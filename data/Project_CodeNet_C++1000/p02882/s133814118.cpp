#include <bits/stdc++.h>
#include <iomanip>
#include <math.h>
#define rep(i,x) for(ll i = 0;i<x;i++)
#define all(a) (a).begin(),(a).end()
using ll = long long;
using ld = long double;
using namespace std;
using dou = double;
const ll INF = 1001001001;
const ll mod = 1000000007;
typedef pair<ll,ll> P;
using graph = vector<vector<ll>>;
ll gcd(ll a,ll b){
    if(a < b)swap(a,b);
    if(a % b == 0)return b;
    else return gcd(b,a%b);
}
bool isp(ll n){
    bool res = true;
    if(n == 1)return false;
    else{
        for(ll i = 2;i * i <= n;i++){
            if(n % i == 0){
                res = false;
                break;
            }
        }
        return res;
    }
}
//printf("%.10f\n", N);
/*
ll memo[100000];
ll fibo(ll n){
    if(memo[n] != 0)return memo[n];
    if(n <= 1)return n;
    else return memo[n] = fibo(n - 1)+ fibo(n - 2);
}*/

int main(){
    double pi = 3.14159265358979;
    /*cout << pi / atan(1.7320508) << endl;*/
    double A,B,X;
    cin >> A >> B >>X;
    dou H = X / A / A;
    if(H  * 2 >= B){
        dou N = 2 * B - 2 * H;
        dou res = atan(N / A);
        printf("%.10f\n",res / pi * 180);
    }
    else{
        dou N = A * B / X * B / 2;
        dou res = atan(N);
        printf("%.10f\n",res / pi * 180);
    }
}