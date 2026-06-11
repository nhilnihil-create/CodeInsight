#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int a, b, x;
double pi = 4.0 * atan(1.0);
bool f(double t){
    double val;
    if(t / 180 * pi >= atan((double)b / (double)a)){
        val = a * b * b * tan(pi/2 - t / 180 * pi) / 2.0;
    }
    else{
        val = a * a * b - a * a * a * tan(t / 180 * pi) / 2.0;
    }

    if(val < x){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    cin >> a >> b >> x;
    double ng = 0;
    double ok = 90;
    double mid;
    while(ok - ng > ok / 100000000){
        mid = (ok + ng) / 2.0;
        if(f(mid)){
            ok = mid;
        }
        else{
            ng = mid;
        }
    }
    printf("%28.12f\n", ok);


}