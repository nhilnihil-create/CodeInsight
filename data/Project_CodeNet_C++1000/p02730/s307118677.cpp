#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,p;
    string s1,s2,s3,s4,s5,s6;
    cin>>s1;
    n=s1.length();
    m=(n+2)/2;
    p=(n-1)/2;
    s2=string(s1.rbegin(),s1.rend());
    if(s1.compare(s2)==0)
    {
        s4=string(s1.begin(),s1.begin()+p);
        s3=string(s1.rbegin()+m,s1.rend());

        if(s3.compare(s4)==0)
        {
            s5=string(s1.begin()+m,s1.end());
            s6=string(s1.rbegin(),s1.rbegin()+p);


            if(s5.compare(s6)==0)
            {
                cout<<"Yes"<<endl;
            }
            else
            {
                cout<<"No"<<endl;
            }
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;

}

