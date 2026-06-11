//Bismillahir Rahmanir Rahim
//sajeedreefy
#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int n,count=0,a,b,i,j;
    cin >> n;
    n=n%1000;
    if(n==0)
    {
        cout << n << endl;
    }
    else
    {
        cout << 1000-n << endl;
    }
    return 0;

}

