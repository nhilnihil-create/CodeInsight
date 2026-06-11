#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define PI 3.14159265358979323846264338327950L
using namespace std;
using P = pair<int,int>;
using ll = long long;
using namespace std;
int main(void){
    int a, b;
    cin >> a >> b;
    int ans = 1;
    int i = 0;
    
    if(b == 1){cout << 0 << endl; return 0;}
    while(ans < b){
        --ans;
        ans += a;
        ++i;
    }
    cout << i << endl;
}
