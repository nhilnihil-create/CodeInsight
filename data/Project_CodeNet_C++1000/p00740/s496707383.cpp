#include<iostream>
#include<string>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
int array[51];
int main(){
  int n,p;
  vector<int> v;
  while(cin >>n >>p){
     if(n==0&&p==0){
       break;
     }
     int i=0,gen=p;
     while(true){
       /*
    for(int s=0;s<n;s++){
	 cout << "人" <<s <<" " <<array[s]  <<endl;
       }
       cout <<"p " << p << endl;
       */

       if(p!=0){
       array[i]+=1;
       p--;
        if(array[i]==gen&&p==0){
	  cout   << i <<endl;
	  array[i]=0;
	  break;
	} 
       }else{
	   p+=array[i];
	   array[i]=0;
       }
   
       i++;
    
       if(i==n){
	 i=0;
       }
     }
  }
 
  return 0;
}