#include <bits/stdc++.h>
using namespace std;
 
int main() {
    long long h;
    cin >> h;
    long long cnt = 0;
    long long num=1;
	long long ans=1;
    while (h != 1){
        h = h/2;
        cnt++;
    }
    for (int i=0; i<cnt; i++){
        num = num*2;
        ans += num;

    }
    cout << ans;
}