#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int N;
    cin>>N;
    vector<int> P;
    for (int i = 0; i < N; i++)
    {
        int p;
        cin>>p;
        P.push_back(p);
    }

    int ans=0,min=N;
    for (int i = 0; i < N; i++)
    {
        if(P[i]<=min)
        {
            ++ans;
            min = P[i];
        }
        if(min==1)
        {
            break;
        }
    }
    
    cout<<ans<<endl;
    return 0;
}