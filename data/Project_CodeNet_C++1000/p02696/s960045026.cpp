#include<bits/stdc++.h>
using namespace std;
long long int n, i, A, B;
int main()
{
    cin >> A >> B >> n;
    if(n>=B)
        cout << (A*(B-1))/B - A*((B-1)/B) << endl;
    else
        cout << (A*n)/B - A*(n/B) << endl;
    return 0;
}
