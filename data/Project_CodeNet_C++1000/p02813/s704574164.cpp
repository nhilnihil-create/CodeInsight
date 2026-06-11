#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <math.h>
unsigned int factorial(unsigned int n){
    if (n==0) return 1;
    else return n*factorial(n-1);
}
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define ll long long
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> p(n),q(n),v(n);
    for (int i=0;i<n;i++) cin>>p[i];
    for (int i=0;i<n;i++) cin>>q[i];
    for (int i=0;i<n;i++) v[i]=i+1;
    int cnt=1;
    int a=0,b=0;

    do{
        if(v==p) a=cnt;
        if(v==q) b=cnt;
        cnt++;
    }while(next_permutation(v.begin(),v.end()));
    cout<<abs(a-b)<<endl;

    return 0;
}