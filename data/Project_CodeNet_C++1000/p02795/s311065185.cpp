#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
struct points{
    int x,y;
};
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    double h,w,n;
    while(cin>>h>>w>>n){
        cout<<ceil(n/max(h,w))<<endl;
    }
    return 0;
}
