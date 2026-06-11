#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100005;
int a[maxn]={0};
long long node[maxn]={0};
int main()
{
    long long sum =0 ;
    int n;
    cin >> n;
    for(int i=0;i<=n;i++){
        cin >> a[i];
        sum+=a[i];
    }
    long long num  = 0 ;
    for(int i=n;i>=0;i--){
        node[i]=node[i+1]+a[i];
    }
    num = 1;
    for(int i=0;i<=n&&num<=sum;i++){

        //cout << num << endl;
        node[i] = min(num,node[i]);
        num = num-a[i];
        if(num<0){
            cout << -1 << endl;
            return 0;
        }

        num*=2;
    }
    sum =0 ;
    for(int i=0;i<=n;i++){
        sum+=node[i];
    }
    cout << sum <<endl;
    return 0;
}
