#include <bits/stdc++.h>
using namespace std;

int main(){
    int x;
    cin >> x;
    int a, b, c, ans;
    a = x/500;
    c = x%500;
    b = c/5;
    ans = 1000*a + 5*b;
    std::cout << ans << std::endl;
}