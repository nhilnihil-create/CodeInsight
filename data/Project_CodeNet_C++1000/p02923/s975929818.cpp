#include <bits/stdc++.h>
using namespace std;
 


int main() {
 int n;
 cin>>n;
 vector<int> vec(n) ;
 for (int i = 0; i < n; i++)
   cin>>vec[i];
 vector<int> count(n,0);
 
 for (int i = 0; i < n-1; i++)
 {
  if(vec[i] >= vec[i+1])  count[i+1] = count[i]+1;
 }
   sort(count.begin(), count.end()); 
 cout << count[n-1] <<endl;
}