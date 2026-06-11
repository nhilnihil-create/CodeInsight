#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s,t; 

    cin>>s>>t; 

    string ans ; 

    int count =0  ,min_1 =INT_MAX; 
    for(int i=0 ;i<s.size() - t.size() +1; i++ )
    {
        int j;
        count =0 ; 
        for(j =0  ; j<t.size() ; j++)
        {
            if(s[i +j]!= t[j])
            {
                count++ ;
            }
        }

        min_1 = min(min_1 , count );
    }

    cout<<min_1; 


    

    
}