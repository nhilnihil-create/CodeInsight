#include<bits/stdc++.h>
using namespace std;
int main(){


 int h,a,cnt=0;
    cin>>h>>a;
 if(h%a==0)
 {
     cnt=h/a;
 }
 else
    cnt=h/a+1;
  cout<<cnt<<endl;



return 0;


}
