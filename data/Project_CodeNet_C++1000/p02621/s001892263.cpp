#include <iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    # ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int a;
    cin>>a;
    cout<<a+a*a+a*a*a<<endl;
    return 0;
}
