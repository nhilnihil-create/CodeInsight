#include<iostream>
#include<cmath>

int abc(long long n)
{
    int  c,b;
    c = ((int)(log10(n)));
    b = (int) (n/(int)(pow(10,c)));
    return b;
}

using namespace std;
int main()
{
    long long n,i,j,total=0;
    cin >> n;
    int a[10][10]={0};
    for(i=1;i<=n;i++)
    {
         if(i%10==0)
            continue;
         else
         {
             j = abc(i);
             a[j][i%10]++;
         }
    }
    for(i=1;i<=9;i++)
    {
        for(j=1;j<=9;j++)
        {
           total = total + a[i][j]*a[j][i];
        }
    }

    cout << total << endl;
    return 0;
}
