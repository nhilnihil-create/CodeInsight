#include<iostream>
using namespace std;
#define H 500000

void maxheapi(int *a,int i,int h){
    int l,r,max;

    if(i>1){
      l=2*i;
      r=2*i+1;
    }else{
      l=i+1;
      r=l+1;
    }
    if(l<=h && a[l]>a[i])max=l;
    else max=i;

    if(r<=h && a[r]>a[max])max=r;

    if(max!=i){
        swap(a[i],a[max]);
        maxheapi(a,max,h);
    }
}
int main(){
  int h,a[H],i;
  cin>>h;
  for(i=1;i<=h;i++){
    cin>>a[i];
  }

for(i=h/2;i>0;i--){
    maxheapi(a,i,h);
}
for(i=1;i<=h;i++){
    cout<<" "<<a[i];
}
cout<<endl;

  return 0;
}

