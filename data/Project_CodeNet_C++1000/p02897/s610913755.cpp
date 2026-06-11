#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    if(n%2==0)
     cout<<float(n/2)/float(n);
    else 
     cout<<float((n/2)+1)/float(n);
     return 0;
}
     
   


