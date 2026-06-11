#include<iostream>
using namespace std;
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
int main(){
  int h,k,h2,k2,K,mins;
  cin>>h>>k>>h2>>k2>>K;
  if(h2>=h)
  {
    if(k2>=k){
      mins=k2-k+60*(h2-h);
    }
    else{
      mins=k2-k+60+60*(h2-h-1);
      if(h==h2){
          mins+=1440;
      }
    }
  }
  else{
    swap(h,h2);
    swap(k,k2);
    if(k2>=k){
      mins=k2-k+60*(h2-h);
    }
    else{
      mins=k2-k+60+60*(h2-h-1);
    }
    mins=1440-mins;
  }
  mins-=K;
  cout<<mins<<"\n";
  return 0;
}