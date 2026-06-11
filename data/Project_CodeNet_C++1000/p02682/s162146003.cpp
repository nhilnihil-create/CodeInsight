#include<iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std;

int main()
{
    int a,b,c,k;
    cin>>a>>b>>c>>k;
    int sum = 0;
    sum = sum + min(a,k);
    k = k - min(a,k);
    //
    k = k - min(b,k); 
    sum = sum - min(c,k);
    k = k - min(c,k);

    cout<<sum<<endl;

}
