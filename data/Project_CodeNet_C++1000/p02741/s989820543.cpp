#include <bits/stdc++.h>
#define r(i,n) for(long long i = 0; i<n; i++)
typedef long long ll;
using namespace std;


int main() {
  int a[32];
  a[0]=a[1]=a[2]=a[4]=a[6]=a[10]=a[12]=a[14]=a[16]=a[18]=a[22]=a[28]=a[30]=1;
  a[3]=a[5]=a[8]=a[9]=a[13]=a[20]=a[21]=a[24]=a[25]=2;
  a[27]=a[29]=4;
  a[7]=a[11]=a[17]=a[19]=a[26]=5;
  a[15]=14;
  a[23]=15;
  a[31]=51;
  int n;
  cin >> n;
  cout<<a[n-1]<<endl;
}
