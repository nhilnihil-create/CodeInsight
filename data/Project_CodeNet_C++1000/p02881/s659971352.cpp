#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<limits.h>
using namespace std;

int main(){
    long long N;
    cin >> N;
    long long ans = LLONG_MAX;
    for(int i = 1; i <= sqrt(N); i++){
        if(N % i == 0){
            ans = min(ans, (N /i - 1) + (i - 1));
        }
    }
    cout << ans << endl;
    return 0;
}