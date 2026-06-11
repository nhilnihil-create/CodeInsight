#include <iostream>
#include <cmath>

using namespace std;

int prime[300001];

int main() {

  int n;

  int count;


  prime[0]=prime[1]=0;

  for(int i=2;i<=300000;i++) prime[i]=1;

  for(int i=2;i<=sqrt(300000);i++) {

    if(prime[i]==1) {

      for(int j=2*i;j<=300000;j+=i) prime[j]=0;

    }

  }

  //for(int i=0;i<=50;i++)  cout << prime[i] << " ";

  while(cin >> n,n) {

    count=0;

    for(int i=n+1;i<=2*n;i++) {

      if(prime[i]==1) count++;

    }

    cout << count << endl;

  }

  return 0;

}