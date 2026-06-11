#include<iostream>
using namespace std;
int main(){
    string a,b;
    cin>>a>>b;
    int i,d=0,c=0,j;
    for(i=0; i<=a.size()-b.size(); i++)
    {
        c=0;
        for(j=i; j<=i+b.size()-1; j++)
        {
            if(a[j]==b[j-i])
            {
                c++;
            }
        }
        if(c>d)
        {
            d=c;
        }
    }
    cout<<b.size()-d;
    return 0;
}