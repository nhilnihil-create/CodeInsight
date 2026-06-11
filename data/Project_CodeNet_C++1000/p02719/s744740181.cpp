#include<bits/stdc++.h>
using namespace std;
long long int n, k, temp;
int main()
{
    cin >> n >> k;
    temp = n%k;
    cout << min(temp, abs(temp-k)) << endl;
}
