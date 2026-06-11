#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
#include<iomanip>
#define rep(i,n) for(int i=0;i<n;++i)
#define mod 1000000007
using namespace std;
int main(){
    long long a,b;  cin>>a>>b;
    double num=(double)a/(double)b;
    cout<<a/b<<" "<<a%b<<" "<<fixed<<setprecision(5)<<num<<endl;
}
