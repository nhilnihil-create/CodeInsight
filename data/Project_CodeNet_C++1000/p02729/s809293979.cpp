#include <iostream>
#include <string>
using namespace std;
int min(int a,int b){
    return a < b ? a : b;
}
int f(int n){
    int res = 1;
    if(n > 1){
        res = n*(n-1)/2;
    }
    else {
        res = 0;
    }
    return res;
}
int main(void){
    int N,M;
    cin >> N >> M;
    int ans = 0;
    ans = f(N) + f(M);
    cout << ans <<endl;
}
