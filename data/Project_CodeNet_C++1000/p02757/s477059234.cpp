#include<bits/stdc++.h>
using namespace std;
int freq[10004];
char str[200005];
int main()
{
    int n, p;
    scanf("%d %d %s", &n, &p, str);
    long long res= 0;
    if(p==2)
    {
        for(int i=n-1; i>=0; i--)
        {
            if(!((str[i]-'0')&1))freq[0]++;
            res+= freq[0];
        }
    }
    else if(p==5)
    {
        for(int i=n-1; i>=0; i--)
        {
            if(str[i]=='5' || str[i]=='0')freq[0]++;
            res+= freq[0];
        }
    }
    else
    {
        freq[0]= 1;
        int mul= 1, rem= 0;
        for(int i=n-1; i>=0; i--)
        {
            rem= ((str[i]-'0')*mul + rem)%p;
            res+= freq[rem];
            freq[rem]++;
            mul*= 10;
            mul%= p;
        }
    }
    printf("%lld\n", res);
    return 0;
}
