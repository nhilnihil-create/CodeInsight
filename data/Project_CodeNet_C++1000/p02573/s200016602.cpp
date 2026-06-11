#include<bits/stdc++.h>
using namespace std;


int root(int a[] ,int i)
{
    if(a[i] ==i )
    {
        return i ; 


    }
    else 
    return root(a , a[i]);
}

void union_1(int a[] , int size[] ,int i , int j)
{
    
    int root_A = root(a , i);

    int root_B = root(a, j);

    if(root_A ==root_B)
    {
        return ; 
    }
    if(size[root_A] >= size[root_B])
    {
        a[root_B] = a[root_A];
        size[root_A]+= size[root_B];
        size[root_B] =0 ; 
    }
    else 
    {
        a[root_A] = a[root_B];
        size[root_B]+=size[root_A];
        size[root_A] =0 ; 
    }
}
int main()
{
    int n,m; 
    cin>>n>>m; 

    int  a[n],size[n];

    for(int i=0 ; i<n;i++)
    {
        a[i] =i ;
        size[i] =1;  
    }

    for(int i=0 ; i<m;i++ )
    {
        int x,y;
        cin>>x>>y;

        union_1(a , size , x -1, y - 1); 



    }
     

    int max_1 = INT_MIN  ;
    for(int i=0 ; i<n;i++ )
    {

        max_1 = max(size[i] , max_1);

        

    }
    cout<<max_1 ; 


}