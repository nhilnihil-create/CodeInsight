#include <bits/stdc++.h>

using namespace std;

int main() {
int n ;  
cin>>n ; 
pair< string , int > p[n] ;  
for (int i=0 ;  i<n  ;  i++ ){cin>>p[i].first ; cin>>p[i].second ;  }
string x ;
cin>>x ; 
bool test  = false   ;
int sum= 0 ;  
for (auto it:p) 
{   if (test)
      sum += it.second ;  
    
    if (it.first == x)
       test = true ; 
       
}
cout<<sum<<endl ; 
}