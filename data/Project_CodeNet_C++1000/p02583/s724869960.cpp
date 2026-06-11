#include<bits/stdc++.h>
using namespace std;
bool check(int x ,int y ,int z)
{

    if(x!=y && y!=z && z!=x)
    {
        if(z <x + y)
        {
            return true ;
        }
        else 
        {
            return false; 
        }
    }
    else 
    {
        return false;
    }

}
int main()
{
    int  n; 

    cin>> n; 



    vector<long long int> a;
    set<long long> s ; 

    for(int i =0 ; i<n;i++ )
    {
        int x;
        cin>> x; 

        a.push_back(x);
    }
    

    sort(a.begin() , a.end());

    long long int sum= 0  ; 

    for(int i=0 ; i<n -1;i++ )
    {
        for(int j = i + 1 ; j<n;j++ )
        {
            for(int k= j+1; k<n ; k++ )
            {
                if(check(a[i], a[j],a[k]))
                {
                    sum++ ; 
                }
                
            }
        }
    }
    cout<<sum<<endl; 


}