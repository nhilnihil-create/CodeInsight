#include <iostream>
#include<string>
#include <cmath>

using namespace std;
typedef long long ll;
const int N =1e7+5;
bool good[N];

void check(ll checkNumber)
{
    while(good[checkNumber]==false)
    {
        checkNumber++;
    }
    cout<<checkNumber;
}

int main()
{
    ll checkNuber,i,j;
    cin>>checkNuber;
    for(i=1;i<N;i++)
    {
        good[i]=true;
    }
    good[1]=false;
        for(i=2;i<N;i++)
        {
            if(good[i])
            {
               for(j=i*i;j<N;j+=i)
               {
                   good[j]=false;
               }
            }
        }
        if(good[checkNuber]==true)
            {cout<<checkNuber;return 0;}
        else
            check(checkNuber);
    return 0;
}