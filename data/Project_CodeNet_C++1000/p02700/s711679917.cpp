#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int flag=1,turn =1;
    while(a>0 && c>0){
        if(turn&1){
            c-= b;
            if(c<=0){
                flag= 1;
                break;
            }
        }
        else{
            a-= d;
            if(a<=0){
                flag=0;
                break;
            }
        }
        turn++;
    }
    if(flag) cout<<"Yes";
    else cout<<"No";
}