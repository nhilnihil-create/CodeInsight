#include<bits/stdc++.h>
using namespace std;

#define pb push_back

vector<int>g[100003];
vector<int>v(100003);
queue<int>q;

int main()
{
    int s,w;
    cin>>s>>w;
    if(s>w)
    {
        cout<<"safe"<<endl;
    }
    else
    {
        cout<<"unsafe"<<endl;
    }
}



