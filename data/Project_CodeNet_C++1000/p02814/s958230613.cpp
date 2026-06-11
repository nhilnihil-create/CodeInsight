#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

int gcd(int a,int b) {
  if(a < b) return gcd(b, a);
    int r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}

int main(){

    int n;
    long long int m;
    cin >> n >> m;

    long long int a[n];
    int s=0;
    for(int i=0;i<n;i++){
      cin >> a[i];
      a[i]/=2;
    }

    long long int l=1;
    for(int i=0;i<n;i++){
        l=l/gcd(l,a[i])*a[i];
    }

    for(int i=0;i<n;i++)if((l/a[i])%2==0)s++;

    if(s>0 )cout << 0 << endl;
    else cout << m/(2*l) +(m%(2*l))/l<< endl;


    

}
