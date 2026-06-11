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
vector<int> vec(n);
rep(n){
    cin>>vec[i];
}

sort(vec.begin(), vec.end());

long double sum=0;

sum= vec[0];
for(int i=1;i<n;i++){
    sum= (sum+vec[i])/2;
}
cout<<sum;
}
