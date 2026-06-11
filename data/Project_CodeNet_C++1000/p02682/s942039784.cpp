#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,n;
  cin >>a>>b>>c>>n;
  if(n<=a) cout << n<<endl;
  if(n>a&&n<=a+b) cout <<a<<endl;
  if(n>a+b) cout << a-(n-a-b)<<endl;
}
