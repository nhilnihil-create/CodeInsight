#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<int>v(N);
    for(int i=0; i<N; ++i)
    {
        cin>>v[i];

    }
    sort(v.begin(),v.end());

    int answer=v[v.size()/2]-v[v.size()/2-1];
    cout<<answer<<endl;
    return 0;

}