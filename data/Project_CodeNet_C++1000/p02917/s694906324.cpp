#include <iostream>
 
using namespace std;
long long n,s,i,x,b[1000000];
int main()
{
    cin >> n;
    for (i=1; i<n; i++)
    
        cin >> b[i];
     s=b[1];
        for (i=2; i<n; i++)
        s+=min(b[i-1],b[i]);
        s+=b[n-1];
        cout<<s;
    return 0;
}