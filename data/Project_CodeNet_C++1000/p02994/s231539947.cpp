#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,l;
    cin>>n>>l;
    vector<pair<int,int>> v(n);
    int min = abs(l),nbapple = 1;
    for(int i = 2;i<=n;++i){
        if(min > abs(l+i-1)){
            min = abs(l+i-1);
            nbapple = i;
        }
    }
    int s = (n-1)*l-n+1;
    for(int i = 1;i<=n;++i){
        if(i == nbapple)
            continue;
        s += i;
    }
    cout<<s;

    return 0;
}