#include<bits/stdc++.h>
using namespace std;
int main()

{
    char c;
    cin>>c;

    for(int i=0;i<25;i++)
    {
        if(i+c<'z')
        {
            printf("%c",i+1+c);
            return 0;
        }
    }
}
