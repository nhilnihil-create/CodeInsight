#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;

typedef long long ll;

bool is_prime(int n)
{
    bool prime = true;
    if(n == 1) return false;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            prime = false;
            break;
        }
    }
    return prime;
}

int main()
{
    int a, d, n;
    while(cin >> a >> d >> n && a && d && n) {
        int cnt = 0, num;
        for(int i = 0; ; i++) {
            num = a + d * i;
            if(is_prime(num)) 
                cnt++;
            
            if(cnt == n) {
                cout << num << endl;
                break;
            }
        }
    }
}