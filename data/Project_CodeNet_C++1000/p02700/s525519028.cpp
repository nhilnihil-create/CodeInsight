#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define endl "\n"

int main(){
    //
    //freopen("input.txt", "r", stdin);
    //
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b,c,d;
    cin>>a>>b>>c>>d;

    int num_taken[2];
    num_taken[0]=ceil((float)a/(float)d);
    num_taken[1]=ceil((float)c/(float)b);

    if(num_taken[0]>num_taken[1]||num_taken[0]==num_taken[1]){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }

}