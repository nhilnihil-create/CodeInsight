#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <climits>

#include <utility>
typedef long long ll;
using namespace std;

int main(void){
  ll a1,a2,b1,b2,t1,t2,sum1,sum2;
  cin>>t1>>t2>>a1>>a2>>b1>>b2;
  sum1=a1*t1+a2*t2;
  sum2=b1*t1+b2*t2;

  if(sum1==sum2){
    cout<<"infinity"<<endl;
    return 0;
  }

  if(a1<b1){
    swap(a1,b1);
    swap(a2,b2);
    swap(sum1,sum2);
  }

  if(sum1>sum2){
    cout<<0<<endl;
    return 0;
  }
  if((((a1-b1)*t1)%(sum2-sum1))==0){
    cout<<(((a1-b1)*t1)/(sum2-sum1))*2<<endl;
    return 0;  
  }
  cout<<(((a1-b1)*t1)/(sum2-sum1))*2+1<<endl;
  return 0;
}
