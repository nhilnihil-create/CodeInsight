#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    int child;
    cin>>N;
    vector<int>sub(N,0);
    for(int i=1;i<N;i++)
    {
        cin>>child;
        sub.at(child-1)++;
        
    }
    for(auto a : sub)
    {
        cout<<a<<endl;
    }
}