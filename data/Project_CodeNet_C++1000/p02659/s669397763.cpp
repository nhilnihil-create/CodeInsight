#include<bits/stdc++.h>
#define Bye return 0
#define ll long long

using namespace std;

void solve(){
    long long a, mult; string b;
    cin>>a>>b;
    int b_c = (b[0]-'0')*100 + (b[2]-'0')*10 + (b[3]-'0');
    mult = (long long) (a*b_c)/100;

    cout<<mult<<endl;
}

int main(){
    solve();
    Bye;
}