
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
   int a,b;
   cin>>a>>b;
   char c1=a+'0';
   char c2=b+'0';

   string s1(b,c1),s2(a,c2);
   cout<<min(s1,s2)<<endl;
   exit(0);
}
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;

    for(int i=0;i<max(a,b);i++)
    {
        cout<<min(a,b);
    }

    cout<<endl;
    exit(0);
}
