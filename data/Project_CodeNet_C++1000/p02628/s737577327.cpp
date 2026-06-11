#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k,a[1010],sum =0;
    cin>>n>>k;
    for(int i =0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int j=0;j<k;j++){
        sum +=a[j];
    }
    cout<<sum<<endl;


    return 0;
}
