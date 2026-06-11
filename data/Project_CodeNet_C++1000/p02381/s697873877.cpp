#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
typedef long double ld;
int n;
vector<ld> data;
int inp(){
  cin>>n;
  if(!n)return 0;
  data=vector<ld>(n);
  for(int i=0;i<n;i++)
    cin>>data[i];
  return n;
}
void proc(){
  ld avg=accumulate(data.begin(),data.end(),0.0)/n;
  transform(data.begin(),data.end(),data.begin(),[avg](ld x)->ld{return (x-avg)*(x-avg);});
  ld result=sqrt(accumulate(data.begin(),data.end(),0.0)/n);
  printf("%Lf\n",result);
}
int main(){
  while(inp())proc();
  return 0;
}