#include<iostream>

using namespace std;
int main()
{
    int v,v1,n;
    cin>>v>>v1>>n;
    int x;
    if(v>v1)x = v;
    else x = v1;int s,sum=0;
    for(int i=1;i<=n;i+=1){
        s = x*i;sum++;
        if(s==n || s>n){
            cout<<sum<<endl;

            return 0;
        }
    }


    return 0;
}
