#include <iostream>
#include<vector>
#include<algorithm>
#define ll long long 
#define rep(n) for(int i=0;i<n;++i)
using namespace std;
int main(void){
    // Your code here!

int n;
cin>>n;
vector<int> vec1(n+1), vec2(n);
rep(n+1){
    cin>>vec1[i];
}

rep(n){
    cin>>vec2[i];
}

ll sum=0;

rep(n){
    int a= min(vec1[i], vec2[i]);
    vec1[i]-=a;
    vec2[i]-=a;
    int b= min(vec1[i+1],vec2[i]);
    vec1[i+1]-=b;
    vec2[i]-=b;
    sum+=(a+b);
}
cout<<sum;
}
