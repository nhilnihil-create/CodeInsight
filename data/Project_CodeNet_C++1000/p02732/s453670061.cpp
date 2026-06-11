#include <iostream>
using namespace std;
int main(){
    int n;
  	cin >> n;
    unsigned long long a[n];
    unsigned long long b[n] = {};
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) b[a[i]-1]++;
    unsigned long long c=0;
    for(int i=0; i<n; i++) c += (b[i]*(b[i]-1))/2;
    for(int i=0; i<n; i++){
      cout << c - b[a[i]-1] + 1 << endl;
    }
 
}