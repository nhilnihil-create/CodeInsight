#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n,x,t;
    cin >> n >> x >> t;
    
    cout<<(int)((int)(ceil(n*1.0/x)) * t)<<endl;
    return 0;
}