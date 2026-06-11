#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n,k,i=0,j,c=0,p,h[1000010];
    cin >> n >> k;
    if(n%k==0)
    {
        cout << '0' << endl;
        return 0;
    }
    if(n<k)
    {
    if(n<abs(n-k))
    {
        cout << abs(n) << endl;
        return 0;
    }
    else
    {
        cout << abs(n-k) << endl;
        return 0;
    }
    }
    if(abs(n%k)<abs(n%k-k))
    {
        cout << n%k << endl;
    }
    else
    {
        cout << abs(n%k-k) << endl;
    }
    return 0;

}
