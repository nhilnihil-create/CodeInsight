#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int N;
    cin>>N;
    deque<int>W;
    for (int i = 0; i < N; i++)
    {
        int w;
        cin>>w;
        W.push_back(w);
    }

    int front=W.front();
    W.pop_front();
    auto T=abs(front-(accumulate(W.begin(),W.end(),0)));
    for (int i = 1; i < N; i++)
    {
        front+=W.front();
        W.pop_front();
        auto t=abs(front-(accumulate(W.begin(),W.end(),0)));
        if (T>t)
        {
            T=t;
        }   
    }
    
    cout<<T<<endl;
    
    return 0;
}