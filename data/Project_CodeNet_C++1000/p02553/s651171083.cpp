#include<bits/stdc++.h>
using namespace std;
long long arr[4];
int main()
{
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    arr[0]=a*c;
    arr[1]=a*d;
    arr[2]=b*c;
    arr[3]=b*d;
    sort(arr,arr+4);
    cout<<arr[3]<<endl;




    return 0;
}
