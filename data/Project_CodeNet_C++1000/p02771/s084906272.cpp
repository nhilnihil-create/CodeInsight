#include <bits/stdc++.h>
#include <vector>
#include <map>
#define ll long long
#define h   "\n"
#define ios
using namespace std;

int main()
{
    int a[3];

    cin>>a[0]>>a[1]>>a[2];

    sort(a,a+3);
 int m=0;
    for(int i=1;i<3;i++)
    {
        if(a[i]==a[i-1])
        m++;
    }


    if(m==1)
        cout<<"Yes"<<h;
        else
            cout<<"No"<<h;

    return 0;
}
