#include<iostream>

using namespace std;

int main(void)

{
    long long int a, b, v, w, t, flag = 0;
    cin>>a>>v>>b>>w>>t;
    flag = a-b;
    if(flag < 0)flag *= (-1);
    if(w >= v)
        cout<<"NO\n";
    else{
    if(flag <= (v-w)*t)cout<<"YES\n";
    else cout<<"NO\n";
    }
    return 0;
}
