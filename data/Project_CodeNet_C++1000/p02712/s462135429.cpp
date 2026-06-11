#include<iostream>
#include<cmath>
#include<iomanip>
#include<set>
using namespace std;
#define ll long long
int main(){
int n;
ll ans=0;
cin>>n;

for(int i=1;i<=n;i++){
    if(i%3==0 || i%5==0)
        continue;
    ans+=i;
}
cout<<ans;

}