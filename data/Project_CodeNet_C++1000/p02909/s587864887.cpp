#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define dbg(x) cout<<"( "<<#x<<" -> "<<x<<" )"<<endl;
using namespace std;
int main()
{
    string s;
    cin>>s;
    if (s.compare("Sunny")==0)
    printf("Cloudy\n");
    else if (s.compare("Cloudy")==0)
    printf("Rainy\n");
    else
    printf("Sunny\n");
    return 0;
}