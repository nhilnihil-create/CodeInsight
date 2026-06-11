#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn= 5e5+5;
#define mod 1000000007
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main() {
    int n;
    cin>>n;
    float temp=ceil(n/1.08);
    if(floor(temp*1.08)==n)
    cout<<temp;
    else cout<<":(";
}

