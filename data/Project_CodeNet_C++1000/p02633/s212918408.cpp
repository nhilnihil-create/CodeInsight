#include <bits/stdc++.h>
using namespace std;
 
int main(){
    
    int n;
    cin>>n;
    int k=1;
    while((k*n)%360!=0)k++;
    cout<<k<<endl;
    
}