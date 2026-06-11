#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    int n, m;
    cin>>n>>m;
    int a[n];
    int total = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        total +=a[i];
    }
    int div = 4*m;
    int k = 0;
    int temp;
    if(total%div == 0)
    temp = total/div;
    else
    {
        temp = total/div + 1;
    }
    for(int i = 0; i < n ;i++){
        
        if(a[i] >= temp)
        k++;
    }
    if(k >= m) cout<<"Yes";
    else cout<<"No";
    return 0;
}