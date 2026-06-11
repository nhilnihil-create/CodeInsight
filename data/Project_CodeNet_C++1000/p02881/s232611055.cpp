#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int main(){
    long long N,X,Y;
    long long ans;
    cin >> N;
    ans = N;
    for(long long i=1;i*i<=N;i++){
        if(N % i == 0){
            X = i;
            Y = N / i;
            ans = min(ans,X-1+Y-1);
        }
    }
    cout << ans << endl;
}
