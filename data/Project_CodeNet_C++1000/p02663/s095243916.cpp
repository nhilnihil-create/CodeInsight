#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int h_1,m_1,h_2,m_2,k;
  cin>>h_1>>m_1>>h_2>>m_2>>k;
  //分数計算
  int time;
  time = (h_2-h_1)*60+(m_2-m_1);
  cout<<time-k<<endl;
  
  

}