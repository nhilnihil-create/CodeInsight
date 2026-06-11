#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
int main(int argc,char* argv[])
{
  int length,input;
  double d1,d2,d3,d4,temp;d1=0;d2=0;d3=0;d4=0;
  vector<int> vec1,vec2;
  cin >> length;
  for(int i=0;i<length;i++)
  {
    cin >> input;
    vec1.push_back(input);
  }
  for(int i=0;i<length;i++)
  {
    cin >> input;
    vec2.push_back(input);
  }
  for(int i=0;i<length;i++)
  {
    d1+=abs(vec1[i]-vec2[i]); 
    d2+=pow(abs(vec1[i]-vec2[i]),2.0); 
    d3+=pow(abs(vec1[i]-vec2[i]),3.0);
    temp=abs(vec1[i]-vec2[i]);
    if(temp>=d4) d4=temp;
  }
    printf("%.8lf\n%.8lf\n%.8lf\n%.8lf\n",d1,sqrt(d2),pow(d3,1.0/3.0),d4);
}