#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    Hello
    int a, b, k, temp = 0;
    cin >> k >> a >> b;
    while(true){
        if(temp >= a && temp <= b)
            return cout << "OK", 0;
        else if(temp > 10000)
            break;
        temp += k;
    }
    cout << "NG";
    return 0;
}