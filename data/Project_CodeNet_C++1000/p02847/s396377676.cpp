#include<bits/stdc++.h>
using namespace std;
using int_greater_PQ = priority_queue<int,vector<int>,greater<int>>;
using d_array=vector<int>;

int main() 
{
    string S;
    cin>>S;

    array<string,7>Y={ "SUN","MON","TUE","WED","THU","FRI","SAT"};
    auto it=find(Y.begin(),Y.end(),S);
    auto ans=(distance(Y.begin(),it));
    cout<<7-ans<<endl;
}