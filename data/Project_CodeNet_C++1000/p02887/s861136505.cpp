#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char s[100001];
    scanf("%s",s);
    int i;
    int countr=1;
    for(i=0;i<n-1;i++)
    {
        if(s[i+1]!=s[i])
        {
            countr++;
        }
    }
    cout << countr;
}
