#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cin >> x;
    int p = x / 100, q = x % 100;
    int cnt = 0;
    
    for(int i = 5; i >= 1; i--){
        cnt += q / i;
        q %= i;
    
    }

    if(cnt <= p) cout << "1" << endl;
    else cout << "0" << endl;
}