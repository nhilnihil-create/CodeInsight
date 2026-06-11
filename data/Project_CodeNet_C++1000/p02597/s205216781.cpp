#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
	int n;
    cin>>n;
    string c;
    cin>>c;
    int sw = 0;
    for(int i= 0;i<n;i++){
    	if(c[i] =='W'){
          sw++;
        }
    }
    int k = 0;
    for(int i = n-1;i>n-1-sw;i--){
    	if(c[i] =='R'){
          k++;
        }
    }
    cout<<k;
    return 0;
}