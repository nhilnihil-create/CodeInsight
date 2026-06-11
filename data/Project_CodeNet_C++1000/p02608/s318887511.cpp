#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n+1]={0};
    for(int x=1;x<=n;x++)
    {
        for(int y=1;y<=n;y++)
        {
            for(int z=1;z<=n;z++)
            {
                int value=x*x+y*y+z*z+x*y+y*z+z*x;
                if(value>n) break;
                arr[value]++;
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<arr[i]<<"\n";
    return 0;

}
