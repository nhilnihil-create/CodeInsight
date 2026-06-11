#include<bits/stdc++.h>
using namespace std;
int main(){
    int N; cin >> N;
    int a,b=0;
    for(int i=0;i<N;++i){cin >> a;b^=a;}
    if(!b)cout<<"Yes";
    else cout<<"No";
 	return 0; 
}