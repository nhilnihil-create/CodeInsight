#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num;
    while(cin>>num)
    {
        set<string> s;
        for(int i=0;i<num;i++)
        {
            string temp;
            cin>>temp;
            s.insert(temp);
        }
        cout<<s.size()<<endl;
    }
}
