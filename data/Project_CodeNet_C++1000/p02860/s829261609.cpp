#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll n;
string s;
int main()
{
    scanf("%lld",&n);
    cin >> s;
    if(n%2)
        printf("No");
    else
    {
        for(int i = 0; i < n/2; i++)
        {
            if(s[i] != s[(n/2)+i])
            {
                printf("No");
                return 0;
            }
        }
        printf("Yes");
    }
    return 0;
}
