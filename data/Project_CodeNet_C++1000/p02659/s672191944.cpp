#include <bits/stdc++.h>
#define ll long long int
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
int main()
{
    ll A;
    double B;
    cin>>A>>B;
    ll BLL=B*100+0.001;
    cout<<(A*BLL)/100<<endl;
    return 0;
}
