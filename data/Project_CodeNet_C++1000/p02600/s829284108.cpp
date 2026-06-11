#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 5;
const int maxm = 5e5 + 5;
const ll inf = 2147483647;
int a[1001];
int main(){
    int x;
    cin>>x;
    if(x >= 400 && x < 600)cout<<8<<endl;
    if(x >= 600 && x < 800)cout<<7<<endl;
    if(x >= 800 && x < 1000)cout<<6<<endl;
    if(x >= 1000 && x < 1200)cout<<5<<endl;
    if(x >= 1200 && x < 1400)cout<<4<<endl;
    if(x >= 1400 && x < 1600)cout<<3<<endl;
    if(x >= 1600 && x < 1800)cout<<2<<endl;
    if(x >= 1800 && x < 2000)cout<<1<<endl;
    return 0;
}
