#include <bits/stdc++.h>
using namespace std;
int main(){
int N; 
cin >> N;  
for (int i = 1; i <= N; ++i) {
int a = i / 1000; 
int b = (i / 100) % 10; 
int c = (i / 10) % 10; 
int d = i % 10; 
 if(i % 3 == 0 || a == 3 || b == 3 || c == 3 || d == 3)
  cout << " " << i;  
}
cout << endl; 
}
