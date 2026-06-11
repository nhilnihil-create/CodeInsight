#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> p(n),q(n),v(n);
    for(auto& P : p)
        cin >> P;
    for(auto& Q : q)
        cin >> Q;
    for(int i = 0; i < n; i++)
        v[i] = i + 1;
    int cnt=1;
    int a=0,b=0;
    do{
        if(v==p) a=cnt;
        if(v==q) b=cnt;
        cnt++;
    }while(next_permutation(v.begin(),v.end()));
    cout<<abs(a-b)<<endl;

    return 0;
}

