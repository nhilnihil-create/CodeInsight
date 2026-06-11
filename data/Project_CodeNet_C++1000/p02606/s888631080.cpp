#include<bits/stdc++.h>
using namespace std;
int main(){
  int l,r,d;
  cin>>l>>r>>d;
  int count =0;
   int quo1=l/d;
   int quo2=r/d;
 	int rem=l%d;
 	if(rem==0)
 	{
    count=quo2-quo1+1;
 }
 else
 {
     count=quo2-quo1;
  } 
  cout<<count<<endl;
}
