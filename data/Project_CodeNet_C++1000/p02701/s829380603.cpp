#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    map<int,queue<string>>kind;
    int sum=0;
    set<string>str;
    for(int i=0;i<N;i++)
    {
        string tmp;
        cin>>tmp;
        str.insert(tmp);
       
    }
    cout<<str.size()<<endl;
}    