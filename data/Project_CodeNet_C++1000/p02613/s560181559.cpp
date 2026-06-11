#include<bits/stdc++.h>
using namespace std;
#define test int t;cin>>t;while(t--)
void fastcode()
{
    /*
    cout<<fixed<<setprecision(2);
    π = 3.141592653;
    itoa to convert any system itoa(n,bin,2)
    */
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main()
{
    /*freopen(" ","r",stdin);
    freopen(" ","w",stdout);*/
    fastcode();
    int a=0,b=0,c=0,d=0;
    test
    {
        string s;
        cin>>s;
        if(s=="AC")
        {
            a++;
        }
        else if (s=="WA")
        {
            b++;
        }
        else if (s=="TLE")
        {
            c++;
        }
        else
        {
            d++;
        }
    }
    cout<<"AC x "<<a<<"\n";
    cout<<"WA x "<<b<<"\n";
    cout<<"TLE x "<<c<<"\n";
    cout<<"RE x "<<d;
    return 0;
}
