
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    std::cout << max(max(a*c,b*d),max(a*d,b*c)) << std::endl;
}