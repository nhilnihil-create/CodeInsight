// link here :
#include <bits/stdc++.h>
using namespace std;

#define NAME "test"
#define show(x) cout << (#x) << " is " << (x) << endl
#define ll long long
#define ms(arr,val) memset(arr,val,sizeof(arr))
#define len length()

const int maxn = 50;
double a[maxn];
int main(){
    //ifstream cin(NAME".inp");
    //ofstream cout(NAME".out");
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    double ans = 0;
    ans = a[0];
    for(int i=1;i<n;i++) ans = (ans+a[i])/2.0;
    cout<<ans;

}
