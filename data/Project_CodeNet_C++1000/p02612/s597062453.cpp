///In the name of Almighty Allah(swt).

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int n,m,cunt=0;
    cin>>n;
    m = n;
    while(m!=0)
    {
        m=m/10;
        cunt++;
    }

    if(cunt <= 3)
        cout<<1000-n<<endl;
    else if(cunt == 4)
    {
        int x,p;
        if(n%1000==0)
            cout<<0<<endl;
        else{
        x = n/1000;
        p = (x+1)*1000;
        cout<<p-n<<endl; }
    }
    else if(cunt == 5)
    {
        cout<<0<<endl;
    }


    return 0;
}

