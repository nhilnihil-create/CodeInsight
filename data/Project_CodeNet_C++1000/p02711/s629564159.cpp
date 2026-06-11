#include <bits/stdc++.h>
using namespace std ;
int main()
{
int a ;
cin >> a ;
if(a%10==7){cout<<"Yes" ;}
else {a=a/10 ;

if(a%10==7){cout << "Yes" ;}
else {a=a/10 ;
if(a%10==7){cout << "Yes" ;}
else cout << "No" ;
}
}

   return 0;
}
