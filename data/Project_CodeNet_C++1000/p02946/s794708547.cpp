#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define PI 3.14159265358979323846264338327950L
using namespace std;
using P = pair<int,int>;
using ll = long long;
using namespace std;
int main(void){
    int k, x;
    cin >> k >> x;
    for(int i = x-k+1; i <= x+k-1; ++i){
        cout << i << " ";
    }
    return 0;
}
