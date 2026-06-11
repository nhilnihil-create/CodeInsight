#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

main(){
    int k,a,b;
    cin>>k>>a>>b;
    int count=0;
    for(int i=a;i<=b;i++){
        if(i%k==0) {
            count++;
            break;
        }
    }
    if(count) cout<<"OK";
    else cout<<"NG";
}