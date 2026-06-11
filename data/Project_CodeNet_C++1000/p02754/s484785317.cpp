#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, a, b, ans=0, ball, nokori;
    cin >> n >> a >> b;
    ball=a+b;
    ans=a*(n/ball);
    nokori=n%ball;
    ans+=min(nokori, a);
    cout << ans <<endl;
    return 0;
}
