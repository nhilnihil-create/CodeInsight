#include<bits/stdc++.h>
using namespace std;
using int_greater_PQ = priority_queue<int,vector<int>,greater<int>>;
using d_array=vector<int>;

int main() 
{
    int N;
    cin>>N;
    string S;
    cin>>S;

    for(auto&s:S)
    {
        s+=N;
        if(s>'Z')
        {
            auto n=(s-'Z')-1;
            s='A';
            s+=n;
        }
    }

    cout<<S<<endl;
}
