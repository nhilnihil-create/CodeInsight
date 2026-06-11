#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,r,s1,r1,s2,r2;
    int d,d1,d2;
    cin>>r;
    int n=r.size();
    s=r;
    reverse(r.begin(),r.end());
    d=s.compare(r);
    s1=s.substr(0,(n-1)/2);
    r1=s1;
    reverse(r1.begin(),r1.end());
    d1=s1.compare(r1);
    s2=r.substr(0,((n+2)/2 )-1);
    r2=s2;
    reverse(r2.begin(),r2.end());
    d2=s2.compare(r2);
    if(d1!=0||d!=0||d2!=0)
        cout<<"No";
    else
        cout<<"Yes";
    return 0;

}
