#include<bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef set <int> se;
#define endl "\n"

void solve(){

int n;
cin>>n;

int a[n];
for(auto i = 0 ;i<n;i++) cin>>a[i];

long long ma = a[0];
long long cnt = 0;
for(int i  =  1;i<n;i++){
    if(a[i]<ma){
        cnt += ma-a[i];
    }
    else ma = a[i];
}

cout<<cnt<<endl;

}
 
 
int main()
{

solve();
 
return 0;
}