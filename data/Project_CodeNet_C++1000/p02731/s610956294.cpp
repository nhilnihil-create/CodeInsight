#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long l;
typedef long long unsigned ull;



int main(){
    double l,len,ht,vol;
    cin>>l;
    len = l/3;
    ht = l - (2*len);
    vol = len*len*ht;
    cout<<fixed<<setprecision(6)<<vol;
    return 0;

}
