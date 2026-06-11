#include<bits/stdc++.h>
using namespace std;
int main(){
    int  n;
    cin>>n;
     int ans=1;
     int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(x==ans)
         ans++;
    }
    if(ans==1)
     cout<<-1<<endl;
    else
     cout<<n-ans+1<<endl;
}