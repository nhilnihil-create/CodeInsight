#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin >>n;
vector <double>num(n,0);
for(int i=0;i<n;i++){
cin >> num.at(i);
}
sort(num.begin(),num.end(),greater<>());  
for(int i=0;i<n-1;i++){
double l,m;
l= num.back();
num.pop_back();
m= num.back();
num.pop_back();
num.push_back((l+m)/2);
}
double ans = num.back();
  
  
cout << ans <<endl; 
}

