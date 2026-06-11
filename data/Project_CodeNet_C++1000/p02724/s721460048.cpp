#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin >> n;
    cout << (n/500)*1000 + ((n%500)/5)*5 << endl;
    return 0;
}
