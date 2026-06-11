#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,t;
    int a,b;
    while(cin>>s)
    {
        a=0;
     int    f=1;
        int  c,d,e;
        b=s.size()-1;
        for(c=0,d=b;c<=b;c++,d--)
        {
            if(s[c]!=s[d])
            {
                f=0;
            }

        }
        if(f==1)
        {
            int p,q;
            p=(s.size()-1)/2.;
            p--;
            f=1;
            for(c=0,d=p;c<=p;c++,d--)
            {
                if(s[c]!=s[d])f=0;
            }
            if(f==1)
            {

                 int p,q;
            p=(s.size()+3)/2.;
            p--;
            f=1;
            for(c=p,d=s.size()-1;c<s.size();c++,d--)
            {
                if(s[c]!=s[d])f=0;
            }
            if(f==1)
            {
                cout<<"Yes"<<endl;
            }
            else
            {
                cout<<"No"<<endl;
            }



            }
            else cout<<"No"<<endl;





        }
        else cout<<"No"<<endl;


    }











    return 0;
}
