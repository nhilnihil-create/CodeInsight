#include<iostream>
using namespace std;

int main()

{
    int n,i,number,cnt=0,j;

    cin >> n;

    i = n;

    while(1)
    {
        for(j=1; j<=i; j++)
        {
            if(i>2&&i%j==0)
            {
                cnt++;
            }
        }

        if(i==2)
        {
            cout << 2 << " " ;

            break;
        }

        else if(cnt!=2)
        {
           cnt=0;
           i++;
           continue;
        }

        else if(cnt==2)
        {
            cout << i << " " ;

            break;
        }
    }
}
