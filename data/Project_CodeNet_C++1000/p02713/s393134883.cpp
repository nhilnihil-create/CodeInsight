#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int gcd(int a, int b) {
    if(a<b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
    int r = a % b;
    while(r)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main(){
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= n;j++)
        {
            for (int k = 1; k <= n;k++)
            {
                sum += gcd(i, gcd(j, k));
            }
        }
    }
    cout << sum << endl;
    return 0;
}   