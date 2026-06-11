#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b,c,d;
    cin >> a >> b >> c >> d;
    long long int i,j,k,l;
    i = a*c;
    j = b*c;
    k = a*d;
    l = b*d;
    cout << max(i,max(j,max(k,l))) << endl;
}
