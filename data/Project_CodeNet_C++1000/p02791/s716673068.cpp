#include <iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<set>
#include<map>
#define INF 1e8
using namespace std;
int main(void){
set<long long> s;
int n, count=0, min=1e9+5;
cin>>n;
for(int i=0;i<n;++i){
    int a;
    cin>>a;
    if(a <min)
    {
        count++;
        min=a;
    }
    
}
cout<<count;
}

