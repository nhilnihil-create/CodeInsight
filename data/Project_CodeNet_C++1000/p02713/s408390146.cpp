#include <iostream>
int main()
{
    int k;
    std::cin >> k;

    int a,b,c,d,e,f,ans=0;

    for(int n=0;k-n!=0;n++)
    {
        for(int m=0;k-m!=0;m++)
        {
            for(int i=0;k-i!=0;i++)
            {
                a=k-i,b=k-m,c=k-n;
                if(a<b) e=a,a=b,b=e;
                d=a%b;
                while(d!=0){
                    a=b;
                    b=d;
                    d=a%b;
                }
    
                if(b<c) e=b,b=c,c=e;
                f=b%c;
                while(f!=0){
                    b=c;
                    c=f;
                    f=b%c;
                }
                ans += c;

            }
        }
    }

    std::cout << ans << std::endl;
    return 0;
}