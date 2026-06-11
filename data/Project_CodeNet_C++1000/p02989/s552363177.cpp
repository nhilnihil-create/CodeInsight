#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int N;
    cin>>N;
    vector<int>D;
    for (int i = 0; i < N; i++)
    {
        int d;
        cin>>d;
        D.push_back(d);
    }
    sort(D.begin(),D.end());

    int ans=D[N/2]-D[(N/2)-1];
    cout<<ans<<endl;
    return 0;
}