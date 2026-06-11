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
    
    auto n=static_cast<double>(N);
    double a;

    if(N%2==0)
    {
        a=(n/2)/n;
    }
    else
    {
        a=((n+1)/2)/n;
    }
    


    cout<<a<<endl;
    return 0;
}

