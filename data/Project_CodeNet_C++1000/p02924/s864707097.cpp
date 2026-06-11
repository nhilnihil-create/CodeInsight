#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    long long int n,sum=0;
    cin>>n;
    rep(i,n-1){
        sum+=i+1;
    }
    cout<<sum<<endl;
}