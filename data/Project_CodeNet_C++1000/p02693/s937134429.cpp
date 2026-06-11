#include<bits/stdc++.h>
using namespace std; 
int main() 
{
    int a,b,k; 
	cin >> k >> a >> b;
    int m=(b/k)*k;
    cout << (a<=m ? "OK" : "NG") << std::endl;
    return 0;
}
