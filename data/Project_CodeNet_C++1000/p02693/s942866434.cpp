

#include<bits/stdc++.h>
#define ll long long

using namespace std;
int main()
{




    long long ai,t,n,a,A,b,B,c=0,k,e,f,g;



    cin >> t>> A>>B;

    while(A <= B)

    {
       if(A % t== 0)
       {
           cout << "OK" <<endl;
           return 0;
       }
       A++;
    }

    cout << "NG"<<endl;





return 0;
}