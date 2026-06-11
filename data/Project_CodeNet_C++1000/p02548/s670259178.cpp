#include <iostream>
#include<bits/stdc++.h> 
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long int ans = 0;
    int i =1;
    for(i=1; i<n; i++){
        if(n%i ==0){
            ans = ans + (n/i) -1;
        }else
        ans = ans + (n/i);
    }
    
    
    cout<<ans<<endl;
}