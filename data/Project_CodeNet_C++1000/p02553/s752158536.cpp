#include <bits/stdc++.h>
#include<vector>
#include<cmath>
using namespace std;
#include<set>
int main()
{
        long long int arr[4];
        for(int i=0;i<4;i++)
        {
            cin>>arr[i];
        }
        long long int a=arr[0]*arr[2];
        long long int b=arr[0]*arr[3];
        long long int c=arr[1]*arr[3];
        long long int d=arr[1]*arr[2];
        long long int e=max(a,max(b,max(c,d)));
        cout<<e;
        
        
}

    
        
        
        
        
        
        
        
    
    