# include <bits/stdc++.h>
using namespace std;
long long n, cnt = 1;
int main(){
    cin >> n;
    while(n >= 1){
        cnt *= 2;
        n /= 2;
    }
    cout << cnt - 1;
}
