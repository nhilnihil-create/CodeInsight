#include<bits/stdc++.h>
using namespace std;


int main() 
{
    string S;
    cin>>S;
    for (int i = 1; i < 5; i++)
    {
        auto s= S[i-1];
        if(s==S[i])
        {
            cout<<"Bad"<<endl;
            return 0;
        }        
    }
    
    cout<<"Good"<<endl;
    return 0;   
}