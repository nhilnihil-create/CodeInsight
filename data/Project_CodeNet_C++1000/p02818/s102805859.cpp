#include <iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<set>
#include<map>
#define INF 1e8
using namespace std;
#define ll long long

#define MAX 100020
int main(void){
    
ll a,b,k;
cin>>a>>b>>k;

if(a>=k){
    cout<<a-k<<" "<<b;
}else{
    k=k-a;
    cout<<0<<" ";
    if(b>=k){
        cout<<b-k;
    }else{
        cout<<0;
    }
}

}