
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n ;
    cin>>n ;
   string st ;
   cin>>st ;
   int i=0;
   int j=st.length()-1 ;
   long long c=0 ;
   while(i<j && i<n && j>=0)
   {
       while(i<n && i<j && st[i]=='R')
            i++ ;
        while(j>=0 && i<j && st[j]=='W')
            j-- ;
        if(i>=n  || j<0 ||i>=j) break ;
        char t=st[i] ;
        st[i]=st[j] ;
        st[j] = t ;
        c++ ;
   }
   cout<<c<<endl ;
}
