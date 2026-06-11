#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    int N;cin>>N;
    int ko = 0;
    for(int i = 1;i<=N;i++){
    	for(int j = 1;j<=N;j++){
          if(i*j <N){
          	ko++;
          }
          else{
          	break;
          }
        }
    }
    cout<<ko;
    return 0;
}