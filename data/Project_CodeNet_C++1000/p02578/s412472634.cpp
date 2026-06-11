#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    int n;cin>>n;
    int a[n];
    long g = 0;
    for(int i= 0;i<n;i++)cin>>a[i];
    for(int i = 1;i<n;i++){
    	if(a[i-1] > a[i]){
        	g+= a[i-1] -a[i];
            a[i] = a[i-1];
        }  
    }
    cout<<g;
    return 0;
}