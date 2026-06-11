// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
int main(){
    int a[3][3],i,j,b[1000],k,n;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cin >> a[i][j];
        }
    }
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> b[i];
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
           for(k=0;k<n;k++)
           {
                if(b[k]==a[i][j])
                a[i][j]=1000;
           }
        }
    }
    if((a[0][0]==1000 && a[0][1]==1000 && a[0][2]==1000)||(a[1][0]==1000 && a[1][1]==1000 && a[1][2]==1000)||
    (a[2][0]==1000 && a[2][1]==1000 && a[2][2]==1000)||(a[0][0]==1000 && a[1][0]==1000 && a[2][0]==1000)||
    (a[0][1]==1000 && a[1][1]==1000 && a[2][1]==1000)||(a[0][2]==1000 && a[1][2]==1000 && a[2][2]==1000)||
    (a[2][0]==1000 && a[1][1]==1000 && a[0][2]==1000)||(a[0][0]==1000 && a[1][1]==1000 && a[2][2]==1000))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    


}
