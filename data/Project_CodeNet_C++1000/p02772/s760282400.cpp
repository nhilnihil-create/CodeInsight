#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, cnt=0, sum=0, a[100];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]%2==0)
            cnt++;
    }
    for(int i=1;i<=n;i++){
        if(a[i]%2==0)
            {
                if(a[i]%3==0 || a[i]%5==0)
                    sum++;
            }
    }
    if(cnt==sum)
        cout<<"APPROVED";
    else
        cout<<"DENIED";
}