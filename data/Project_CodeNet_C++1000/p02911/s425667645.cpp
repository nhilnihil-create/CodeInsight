#include<iostream>
#include<vector>

using namespace std;

int main() 
{
    int N,K,Q;
    cin>>N>>K>>Q;

    vector<int> P(N,K);//参加者0-Nごとの得点
    vector<int> A;
    for(int i=0;i<Q;++i)
    {
        int a;
        cin>>a;
        A.push_back(a);
    }

    for(const auto&a:A)
    {
        ++P[a-1];
    }

    for(auto&p:P)
    {
        p-=Q;
    }

    //yes or no
    for(const auto&p:P)
    {
        if(p>0)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    return 0;
}
