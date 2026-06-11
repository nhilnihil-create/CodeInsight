#include <bits/stdc++.h>
#include <vector>
#include <string.h>

typedef long long ll;
typedef long double lg;
using namespace std;


int main(){

 long long lives,n;
 cin>>lives>>n;
   int a[n];

 for(int i=0;i<n;i++){
    cin>>a[i];
 }

 long long sum=0;
 int flag = 0;

 for(int i=0;i<n;i++)
{
  sum += a[i];
  if(sum >= lives){
      flag = 1;
      break; }
 }

 if(flag  == 1)
    cout<<"Yes"<<endl;
 else
 cout<<"No"<<endl;


return 0;
}