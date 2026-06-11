#include <iostream>
#include <cstring>
using namespace std;
char s[1100],t[1100];
int ans=2333333;
int main(void)
{
    cin>>s>>t;
    int ls=strlen(s),lt=strlen(t);
    for(int i=0;i<=ls-lt;i++)
    {
        int k=0;
        for(int j=0;j<lt;j++)
        {
            if(s[i+j]!=t[j])k++;
        }
        ans=min(ans,k);
    }
    cout<<ans<<endl;
    return 0;
}
