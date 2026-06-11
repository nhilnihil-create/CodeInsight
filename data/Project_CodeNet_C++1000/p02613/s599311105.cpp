#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    

   /* AC x 10
   WA x 0
   TLE x 0
   RE x 0*/
   int op1 ,op2,op3,op4 ;
   op1 = op2 = op3 = op4 = 0;
    while(n --)
    {
        string s;
        cin>>s;

        if(s == "AC")
          op1++;
        else if(s == "WA")
          op2++;
        else if(s == "TLE")
          op3++;
        else if(s == "RE")
          op4++;
    }

    cout<<"AC x "<<op1;
    cout<<"\nWA x "<<op2;
    cout<<"\nTLE x "<<op3;
    cout<<"\nRE x "<<op4;
    
}