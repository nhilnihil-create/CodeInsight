#include <iostream>

using namespace std;
int m,d,i,j,nr;
bool ok;
int main()
{
    cin>>m>>d;
    for(i=1;i<=m;i++)
    {
        ok=false;
        for(j=22;j<=d;j++)
        {
            if((j%10)*(j/10)==i && j%10>=2)
            {
                nr++;
            }
        }
    }
    cout<<nr;
    return 0;
}
