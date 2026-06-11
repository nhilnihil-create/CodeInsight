#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int H,N;
    cin>>H>>N;

    vector<int>A;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin>>a;
        A.push_back(a);
    }
    for (auto a:A)
    {
        H-=a;
    }
    
    if(H>0)
    {
        cout<<"No"<<endl;
    }
    else
    {
        cout<<"Yes"<<endl;   
    }
    

    return 0;
}
