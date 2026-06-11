#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a[]={"SAT","SUN","MON","TUE","WED","THU","FRI"};
    int c[]={1,7,6,5,4,3,2};
    string b;
    cin>>b;
    for(int i=0; i<7; i++)
    {
        if(a[i]==b)
        {
            cout<<c[i]<<endl;
            return 0;
        }
    }
}
