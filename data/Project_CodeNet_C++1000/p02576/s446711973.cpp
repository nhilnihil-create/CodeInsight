#include <bits/stdc++.h>
using namespace std;
 
int main() {
int n,x,t;
cin >> n >> x >> t;
int result;
if (n%x!=0)
{
    /* code */


result = (n/x +1)*t ;
}
if (n%x==0)
{
    result = (n/x)*t;
}


cout << result  << endl;
}