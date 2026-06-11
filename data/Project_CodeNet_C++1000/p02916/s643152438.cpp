#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;

int a[100];
int b[100];
int c[100];

int main() {
    int n;cin>>n;
    for(int i = 0;i<n;i++) cin >>a[i];
    for(int i = 0;i<n;i++) cin >>b[i];
    for(int i = 1;i<n;i++) cin>>c[i];
    int m;
    for(int i = 0;i<n;i++){
      m+=b[a[i]-1];
      if(a[i] == a[i-1]+1) m+= c[a[i-1]];
    }
    cout<<m;
    return 0;
}