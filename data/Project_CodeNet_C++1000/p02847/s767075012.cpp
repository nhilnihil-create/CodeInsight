#include <bits/stdc++.h>
#define ll long long int
#define dbg(x) cout<<"( "<<#x<<" -> "<<x<<" )"<<endl;
using namespace std;
int main()
{
    string s;
    cin>>s;
    if (s=="SUN")
    printf("7\n");
    else if (s=="MON")
    printf("6\n");
    else if (s=="TUE")
    printf("5\n");
    else if (s=="WED")
    printf("4\n");
    else if (s=="THU")
    printf("3\n");
    else if (s=="FRI")
    printf("2\n");
    else
    printf("1\n");
    return 0;
}