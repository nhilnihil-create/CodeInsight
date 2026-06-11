#include <bits/stdc++.h>
#define ll long long
#define ar array
#define nl '\n'
#define AC ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
const int M = 1e9+7;
const int N = 2*1e5;


int main(){
    AC
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    int turn = 1;
    while(a>0 && c>0){
        if(turn){
            c-=b;
            turn=0;
        }
        else{
            a-=d;
            turn=1;
        }
    }
    if(a>0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}