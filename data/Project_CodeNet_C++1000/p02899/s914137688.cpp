#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;	cin >> n;
  map<int,int>	a;
  for(int i=0;i<n;i++){
    int time;	cin >> time;
    a[time]=i+1;
  }
  
  for(auto	stu:a){
    cout << stu.second << " ";
  }
  
}