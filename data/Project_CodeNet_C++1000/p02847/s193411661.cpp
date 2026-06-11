#include <bits/stdc++.h>
using namespace std;
#define pi 2*asin(1.0)



long upDiv(long a,long b){
  return (a+b-1)/b;
}

/////////////////////////


//Answer


int main() {

string S;
cin>>S;
if(S=="MON"){
cout<<6<<endl;
}else if(S=="TUE"){
cout<<5<<endl;
}else if(S=="WED"){
cout<<4<<endl;
}else if(S=="THU"){
cout<<3<<endl;
}else if(S=="FRI"){
cout<<2<<endl;
}else if(S=="SAT"){
cout<<1<<endl;
}else{
cout<<7<<endl;
}


}