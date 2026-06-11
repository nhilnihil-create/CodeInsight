#include<bits/stdc++.h>
using namespace std;
int main()
#define rev(x) reverse((x).begin(),(x).end())
{
    string a;
    cin>>a;
    string b=a;
    rev(b);
    if(a!=b)
        cout<<"No\n";
    else
    {
        int x=(a.size()-1)/2;
        string c=a.substr(0,x);
        string d=c;
        rev(d);

        int y=a.size()-((a.size()+3)/2-1);
        string e=a.substr((a.size()+3)/2-1,y);
        string f=e;
        rev(f);

        if(c==d && e==f)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}
