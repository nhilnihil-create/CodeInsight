#include<iostream>
using namespace std;

int main(){
    
    int n,m; cin >> n >> m;
    
    int *fruit = new int [n];
    for(int i=0;i<n;i++){
      cin >> fruit[i];
      
    }
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        if(fruit[i]>fruit[j]){
          int temp = fruit[i];
          fruit[i] = fruit[j];
          fruit[j] = temp;
        }
      }
    }
    
    for(int i=1;i<n;i++)fruit[i] += fruit[i-1];
 
   printf("%d\n",fruit[m-1]);
    

  

  
  return 0;
}