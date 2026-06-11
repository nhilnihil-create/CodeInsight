#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,flag=0,i=n-1;
    char s[i];
    scanf("%d",&n);
    scanf("%s",s);
    if(n%2) printf("No");
    else{
        for(int j=0;j<(n/2);j++)
        {
            if(s[j]!=s[j+(n/2)])
                flag=1;
        }
        if (flag==1) printf("No");
        else printf("Yes");
    }

    return 0;
}
