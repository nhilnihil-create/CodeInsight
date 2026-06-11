#include<bits/stdc++.h>
using namespace std;

const int inf = 1000000000;
int main()
{
    int N,k=inf,c=0;
    cin >> N;
    vector<int>X(N);
    for(int i=0; i<N; i++)
        cin>>X[i];
    for(int i=1; i<=100; i++)
    {
        c=0;
        for(int j=0; j<N; j++)
            c+=(X[j]-i)*(X[j]-i);
            k= min(k,c);
    }
    cout<<k<<endl;
    return 0;
}