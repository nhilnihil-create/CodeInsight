#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
using namespace std;
int main(){
    int N;
    cin >> N;
    int n = N;
    int cnt = 0;
    int k = 1;
    while(n > 0){
        if(n / 10 != 0) k *= 10;
        n /= 10;
        cnt++;
    }
    int ans = 0;
    if(cnt % 2 == 1){
        ans += N - k + 1;
    }
    int t = 1;
    int tem = 10;
    for(int i = 1; i < cnt; i++){
        if(i % 2 == 1){
            ans += tem - t;
        }
        tem *= 10;
        t *= 10;
    }
    cout << ans << endl;
}