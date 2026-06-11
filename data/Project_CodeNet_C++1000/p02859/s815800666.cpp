#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long u_ll;
typedef pair<int, int> pair_;
 
const int INF = 1001001001;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
int k;
 
int gcd(int a, int b){
    if(b == 0) return a;
 
    return gcd(b, a%b);
}
 
int main(){

    int r;

    cin >> r;

    cout << r*r;

    return 0;
}