#include <bits//stdc++.h>
#define rep(i,n) for(int i = 0;i < n;i++)
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    ll sum=0,a[202020],mind,front=0;
    rep(i,n){
        cin >> a[i];
        sum+=a[i];
    }
    mind=sum;
    for(int i = 0;i < n-1;i++){
        front+=a[i];
        sum-=a[i];
        if(abs(sum-front)<mind){
            mind=abs(sum-front);
        }
    }
    cout << mind << endl;
    return 0;
}