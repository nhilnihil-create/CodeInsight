#include<bits/stdc++.h>
#define ll long long

using namespace std;
int main()
{
    vector<int>v;
    vector<int>v1;
    vector<int>v2;
    set <char>s;
    //int t,coun1=0,a,ans3,coun2=0,x,y=0,ans1=0,b,sum=0,flag=0,ans2;




    long long ai,t,n,a,b,sum=0,c=0,k,e,f,g;
    /*string str;
    string str1;

    getline(cin,str);
    getline(cin,str1);*/

    cin >> a >>b >>c >> k;








    if( a == k || a>k)
    {


     cout << k << endl;


    }
    else
    {
        sum=a;

        f=k-a;
        if(f >b )
        {
            sum=sum+b*0;
        }
        else
        {
            sum+=f*0;
        }

        g=k-a-b;

        if(g >0 && g !=0)
        {
            sum+=g*(-1);
        }

        cout << sum;



    }



return 0;
}



