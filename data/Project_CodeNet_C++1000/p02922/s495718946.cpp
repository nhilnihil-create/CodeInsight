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
    int a,b;
    cin>>a>>b;
    a--;b--;
    int temp=b/a+(b%a!=0);
    cout<<temp;
}

