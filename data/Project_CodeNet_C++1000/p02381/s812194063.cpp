#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main(){
  int n;
  while(cin>>n,n!=0){
    double s[n];
    double ave=0;
    for(int i=0;i<n;i++){
      cin>>s[i];
      ave+=s[i];
    }
    ave/=n;
    double var=0;
    for(int i=0;i<n;i++)
      var+=((s[i]-ave)*(s[i]-ave));
    var/=n;
    printf("%.8lf\n",sqrt(var));
  }
  return 0;
}