#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define ll long long
int main()
{
    int n;
    int ans1 = 0;
    int ans2 = 0;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    int pre = -100;
    for(int i = 0; i < n; i++){
        if(pre <= a[i]-1){
            pre = a[i]-1;
        }
        else if(pre <= a[i]){
            pre = a[i];
        }
        else{
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}
