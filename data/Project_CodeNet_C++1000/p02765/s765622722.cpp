#include <iostream>
#include<string>
 using namespace std;

 int main(){
     int K, N;
     cin>>K>>N;

//K>=10 , In Rate=Out
//In Rate= Displayed Rate+100*(10-K)

if(K>=10){cout<<N;}
else {cout<<N+(100*(10-K));}

     }