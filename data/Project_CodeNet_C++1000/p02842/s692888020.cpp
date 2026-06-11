#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    double n;cin>>n;
    for(int i = 0;i<50000;i++){
    	double k = i;
        int a = i*1.08;
        if(a == n){
          cout<<i;
          return 0;
        }   
    }
    cout<<":(";
    return 0;
}