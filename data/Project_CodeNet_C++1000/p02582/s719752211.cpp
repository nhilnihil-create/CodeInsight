#include<bits/stdc++.h>
using namespace std;
string a;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>a;
    int i,c=0;
    for(i=0;i<3;i++)
    {

        if(a[i]=='R'&& a[i+1]=='R')
        {
            c+=2;
            i++;
        }
       // else //if((a[i]=='S'&& a[i+1]=='R')||(a[i]=='R'&& a[i+1]=='S'))
        //{
          //  c++;
            //i++;
        //}
        else if(a[i]=='R'&&a[i+1]=='S'&&a[i+2]=='R')
        {
            c=1;
            break;
        }
        else if(a[i]=='R')
        {
            c++;
        }


    }
   cout<<c<<endl;

    return 0;
}
