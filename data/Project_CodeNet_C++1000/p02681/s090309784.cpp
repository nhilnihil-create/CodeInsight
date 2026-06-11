#include<bits/stdc++.h>
using namespace std;
string s,t;
void input()
{
      cin>>s>>t;
}
void result()
{
    t.pop_back();
    if(s==t){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}
int main()
{
    input();
    result();
    return 0;
}
