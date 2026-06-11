#include<iostream>
#include<queue>
#include<algorithm>
#include<numeric>
#include<string>
#include<map>
#include<bitset>

using namespace std;
using int_greater_PQ = priority_queue<int,vector<int>,greater<int>>;


int main() 
{
    int N;
    cin>>N;

    map<int,int>A;
    for(int i=0;i<N;++i)
    {
        int a;
        cin>>a;
        A.emplace(a,i+1);
    }

    for(const auto&a:A)
    {
        cout<<a.second<<" ";
    }
    cout<<endl;
}