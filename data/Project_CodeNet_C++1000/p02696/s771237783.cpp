#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll a,b,n,x,flag=0,res,choto,boro,lower;
    cin>>a>>b>>n;
    if(n<=b - 1) //ei x er jonnoi max value pabo, eitai x er amon man j b er kacher choto value
    {
        cout<< floor((a*n)/b)-a*floor(n/b)<<endl;
    }
    else if(b - 1<n)// mane x>b case :  x  er amon man khujbo ja b er kacher choto . jehutu x>b thle x er kacher choto hobe b er 1 kom
    {
        choto=b-1; //kacher choto always b-1 hobe
        cout<< floor((a*choto)/b)-a*floor(choto/b)<<endl;
    }
    return 0;
}