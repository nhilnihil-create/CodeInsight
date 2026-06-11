#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N ;
    vector<int> A(N);
    for(int i=0; i<N; i++)
    {
        cin >> A.at(i);
    }
    int max=0;
    vector<int> B(N);
    for(int i=0; i<N; i++)
    {
        if(max<A.at(i))
        {
            max=A.at(i);
        }
        B.at(i)=A.at(i);
    }
    sort(B.begin(),B.end());
    reverse(B.begin(),B.end());
    int submax=max;
    for(int i=0; i<N; i++)
    {
        if(!(B.at(i)==max))
        {
            submax=B.at(i);
            break;
        }
    }
        for(int i=0; i<N; i++)
    {
        if(!(B.at(i)==max))
        {
            submax=B.at(i);
            break;
        }
    }
    if(B.at(0)==B.at(1))
    {
        for(int i=0; i<N; i++)
        cout << max << endl;
    }
    else
    {
        for(int i=0; i<N; i++)
    {
        if(!(A.at(i)==max))
        {
            cout << max << endl;
        }
        else
        {
            cout << submax << endl;
        }
    }
    }
}
