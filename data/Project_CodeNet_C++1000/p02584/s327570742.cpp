#include<bits/stdc++.h>
using namespace std;
int main()
{

     long long int n,i,j=1,c=0,f=0000000000,l,k,x,y,z,m,b,a;
     string s="",s1;
     char o;
     set <int, greater <int> > st;
     stack<char>sta;
     //int a[5];
    //long long  int arr[n+2][n+2];
     vector<char>ch(27);
     vector<string>str;
     vector<int>vect,vect3;
     map<int,int>mp;
     cin>>n>>k>>l;
     x=abs(n)/l;
     if(k<=x)
        cout<<abs(n)-l*k<<endl;
     else
     {
         if((x-k)%2)
            cout<<abs(abs(n)-(x+1)*l)<<endl;
         else
            cout<<abs(abs(n)-x*l)<<endl;
     }
}

