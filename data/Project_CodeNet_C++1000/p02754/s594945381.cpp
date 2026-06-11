#include<bits/stdc++.h>
using namespace std;

int main(){  
  unsigned long long int n,a,b;
  cin >> n >> a >> b;
  
  unsigned long long int count = 0;
  unsigned long long int hikerukaisu = n / (a + b);
  unsigned long long int nokori = min(a,n % (a + b));
  
  cout << hikerukaisu * a + nokori << endl; 
}