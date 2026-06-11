#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N,X;
    cin >> N >> X;
    vector<int> L(N);
    for(int i=0; i<N; i++)
    {
        cin >> L.at(i);
    }
    int64_t count=0;
    int64_t sum=0;
    for(int i=0; i<N; i++)
    {
        sum+=L.at(i);
        if(sum<=X)
        {
            count++;
        }
    }
    cout << count+1<< endl; 
    
}
