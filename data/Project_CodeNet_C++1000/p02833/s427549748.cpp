#include<iostream>
#include<algorithm>
#include<math.h>
typedef long long ll;
using namespace std;

int main(){
    ll N, ans;   cin >> N;
    ans = 0;
    if(N%2==0){
        for(int j=1; j<=25; j++){
          ans += N/10;
          N /= 5;
        }
    }
    cout << ans;
}