#include<bits/stdc++.h>
using namespace std;

int main()
{

    int n,count =0; 
    double d; 

    cin>>n>>d ; 


    for(;n--; )
    {
        long long x ,y; 

        cin>>x>>y; 

        if(sqrt(pow(x,2)  + pow(y,2)) <= d)
        {
            count++; 

        }
    }

    cout<<count;


}