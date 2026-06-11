#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int arr[301];

int main()
{
    int n,k,result=0;
    cin>>n;

    for(int i=1 ; i<=n ; i++)
    {
        cin>>k;
        if(i%2 != 0 && k%2 != 0 )
            result++;
    }

    cout<<result;





    return 0;
}
