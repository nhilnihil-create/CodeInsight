#include <iostream>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#define INF 1e8
using namespace std;
int main(void){
set<long long> s;
int n,k;
cin>>n>>k;

int ar[n];
for(int i=0;i<n;i++){
    cin>>ar[i];
}
long long sum=0;
sort(ar, ar+n);
for(int i=0;i<(n-k);i++){
    sum+=ar[i];
}

cout<<sum;
}

