#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mxn= 1e6+5;
// check for forloop
// intialize variable
// overflow
// go for easy solution
#define mod 1000000007
ll INF = 1000000000000000005LL;
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main(){
    rishabh();
    int a,b;
    cin>>a>>b;
    for(int i=1;i<1010;i++){
        if((i*8)/100==a&&(i)/10==b){
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
}