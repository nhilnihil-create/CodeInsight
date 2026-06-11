#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,j,flag=0;
    cin>>n;
    for(i=0;i<10;i++){
        for(j=i;j<10;j++)
        {if(i*j==n)
            {
            flag++;
            break;
            }
        }
    }
    if(flag==0)
    cout<<"No"<<endl;
    else
    {
        cout<<"Yes"<<endl;
    }
    
    

    
}