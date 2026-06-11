#include <iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main() {
  while(1){
    int n;
    cin>>n;
    if(n==0)break;
    int s[n];
    double sum=0;
    for(int i=0;i<n;i++){
      cin>>s[i];
      sum+=s[i];
    }
    double a=0;
    sum/=n;
    for(int i=0;i<n;i++)a+=(s[i]-sum)*(s[i]-sum)/n;
    cout<<setprecision(10);
    cout<<sqrt(a)<<endl;
  }//pow(s[i]-m,2)
  return 0;
}/*
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    int n;
    while(1){
        cin >> n;
        if(n==0) break;
        int a[n];
        for(int i=0;i<n;i++) cin >> a[i];
        double m = 0;
        for(int i=0;i<n;i++) m += a[i];
        m /= n;
        double b = 0;
        for(int i=0;i<n;i++) b += (a[i]-m)*(a[i]-m)/n;
        cout << setprecision(10);
        cout << sqrt(b) << endl;
    }
}*/