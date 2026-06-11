#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
 int n,m;
 vector<int> v;
 cin >> n >> m;

 for(int i = 0; i < n; i++){
  int tmp;
  cin >> tmp;
  v.push_back(tmp); 
 }
  
 sort(v.begin(),v.end(),greater<int>());
 double sum = 0.0;
 for(int i = 0; i < n; i++){
	sum += v[i];
 }
 double limit = sum / (4.0 * m);
  
 for(int i = 0; i < m; i++){
   if(limit > (double)v[i]){
   cout << "No" ;
   return 0;
  }
 }
  

  
  cout << "Yes";
  return 0;
}