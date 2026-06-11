#include<bits/stdc++.h>
using namespace std;
int main(){
int N,X,T;
cin >>N>>X>>T;
if(N%X == 0){
cout<< N*T/X<<endl;
}
else{
int c = N/X;
c++;
cout << c * T <<endl;
}
}