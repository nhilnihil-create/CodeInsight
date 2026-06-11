#include "iostream"
#include<vector>
using namespace std;
int arr[100000];
int main()
{
    int n,k,q;
    cin>>n>>k>>q;

    for(int i=1;i<=n;i++)
    {
        arr[i]=k-q;
    }

    int min;
    for(int i=0;i<q;i++)
    {
        cin>>min;
        

        arr[min]=arr[min]+1;
        
    }
    
    for(int i=1;i<=n;i++)
    {
        if(arr[i]>0)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
        
    }
    
    
    
    
}


